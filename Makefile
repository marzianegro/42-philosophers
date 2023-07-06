# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegro <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 14:26:29 by mnegro            #+#    #+#              #
#    Updated: 2023/07/06 10:11:52 by mnegro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### PHONY TARGET ###
.PHONY: all clean fclean re

### SILENT TARGET ###
.SILENT:

### VARIABLES (DEFINITION) ###
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -f

#### TARGETS ####
MSRCS = initAll.c libft.c main.c monitorPhilos.c threadRoutine.c \
			utils.c

MOBJS = ${MSRCS:.c=.o}
DIROBJS = obj/
OBJS = ${addprefix ${DIROBJS},${MOBJS}}

INCLUDE = ./philo.h

### (EXPLICIT) RULES ###
${DIROBJS}%.o: %.c
	@echo "${YELLOW}Compiling:${WHITE} $< ${DEF_COLOR}"
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -I {INCLUDE} -o ${NAME}
	@echo "Rule 'all' for mandatory ${NAME} executed successfully!"

clean:
	${RM} ${OBJS}
	@echo "Rule 'clean' for ${NAME} executed successfully!"

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	@echo "Rule 'fclean' for ${NAME} executed successfully!"

re:	fclean all
	@echo "Rule 're' for ${NAME} executed successfully!"

### (BRIGHT) COLORS ###

DEF_COLOR = \033[0;39m
BLACK = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[1;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
