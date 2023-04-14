# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 12:37:40 by agomez-u          #+#    #+#              #
#    Updated: 2023/04/14 12:19:03 by agomez-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./sources/ft_numeric.c \
		./sources/ft_ascii.c \
		./sources/ft_format.c \
		./sources/ft_printf.c \

CC	= gcc
OBJS	= $(SRCS:.c=.o)
RM 	=	rm -f
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
INCS	= .

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): $(OBJS)
	${LIBC} $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re .c .c.o
