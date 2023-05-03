char *get_next_line(int fd)
{
    static char *buffer = NULL;
    int bytes_read;
    char *line = NULL;
    int status;

    if (fd < 0)
        return (NULL);
    while (buffer == NULL || ft_strchr(buffer, '\n') == NULL)
    {
        bytes_read = read_buffer(fd, &buffer);
        if (bytes_read <= 0)
            break;
    }

    if (bytes_read < 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }

    status = process_buffer(&buffer, &line);

    if (status == 0)
    {
        free(buffer);
        buffer = NULL;
    }

    if (line[0] == '\0' && status != 0)
    {
        free(line);
        return (ft_strdup("\n"));
    }
    else if (line[0] == '\0' && status == 0)
    {
        free(line);
        return (NULL);
    }

    return (line);
}

int main(void)
{
    int fd = open("./ascii.txt", O_RDONLY);
    char *line = NULL;

    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }

    close(fd);
    return (0);
}

