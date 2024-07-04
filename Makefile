# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 08:13:40 by rothiery          #+#    #+#              #
#    Updated: 2024/07/04 08:46:02 by rothiery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	libftprintf.a

SRC=	ft_functions.c	ft_hex.c	ft_printf.c	ft_strlen.c	ft_strdup.c

OFILES= ${SRC:.c=.o}
OFILESB=${SRCB:.c=.o}
OFILESALL=${OFILES} ${OFILESB}

${NAME}:${OFILES}
	@ar rcs	${NAME} $?
	@echo "\n\n ${GRAS}${RED}push_swap EST COMPILÉ${RESET}"

CC=	cc
CFLAGS=	-Wall -Wextra -Werror

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
DARK_RED = \033[38;5;88m
GREEN = \033[38;5;85m

#change value by number of files in src !
NBR_TOT_FICHIER = 5

FICH_COUNT = 0
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
REST = ${shell expr 23 - ${BAR}}

all:	${NAME}

${MAIN_PATH}%.o:%.c .
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo " ${GRAS}${RED}-> COMPILATION EN COURS${RESET}${GRAS}${GREEN}${RESET}"
	@printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}$<  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER}
	@echo "${UP}${UP}${UP}"
	@echo ""

clean:
	@rm -f ${OFILESALL}
	@echo "${ORANGE}${GRAS}\tNETTOYAGE${RESET}"
	@echo "${RED}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean:	clean
	@rm -f ${NAME}
	@${RM} ${NAME}
	@echo "${RED}${ITALIQUE} -${NAME} est supprimê${RESET}"

re:	fclean all

.PHONY:	all clean fclean re
