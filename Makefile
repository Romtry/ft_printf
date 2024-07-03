# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rothiery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 08:13:40 by rothiery          #+#    #+#              #
#    Updated: 2024/05/16 12:35:47 by rothiery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libftprintf.a

SRC=	ft_functions.c	ft_hex.c	ft_printf.c	ft_strlen.c	ft_strdup.c

OFILES=	${SRC:.c=.o}

${NAME}:${OFILES}
	ar rcs ${NAME} $?

CC=	cc
CFLAGS=	-Wall -Wextra -Werror

%.o:	%.c
	${CC} ${CFLAGS} -c $? -o $@

all:	${NAME}

clean:
	rm -f ${OFILES}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
