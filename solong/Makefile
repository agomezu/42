# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g -I$(INCPATH) -I$(INCPATH)minilibx_linux -Iget_next_line/
# Name of the output file
NAME = so_long
# Path to source files
SRCPATH = srcs/
# Path to header files
INCPATH = includes/
# Source files
SRCS = $(wildcard $(SRCPATH)*.c) $(wildcard get_next_line/*.c)
# Object files
OBJS = $(SRCS:.c=.o)
# MinilibX flags
MLX = -lmlx -lXext -lX11
# Linker flags
LDFLAGS = -L$(INCPATH)minilibx_linux/
# Libft
LIBFT = libft/libft.a
# Command to remove files
RM = rm -f
# Colors
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m	# No color

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ \
	&& echo "$(GREEN)so_long compiled successfully!$(NC)" \
	|| echo "$(RED)Compilation failed$(NC)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ \
	&& echo "$(GREEN)$@ compiled successfully!$(NC)" \
	|| echo "$(RED)Compilation of $@ failed$(NC)"

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(RM) $(OBJS) && echo "$(GREEN)Object files removed!$(NC)" \
	|| echo "$(RED)Could not remove object files$(NC)"
	@$(MAKE) -C libft clean

fclean: clean
	@$(RM) $(NAME) && echo "$(GREEN)so_long removed!$(NC)" \
	|| echo "$(RED)Could not remove so_long$(NC)"
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
