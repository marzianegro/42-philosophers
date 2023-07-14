# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegro <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 14:26:29 by mnegro            #+#    #+#              #
#    Updated: 2023/07/14 16:07:00 by mnegro           ###   ########.fr        #
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
FL_SRCS = initAll.c libft.c lonePhilo.c main.c \
			monitorPhilos.c threadRoutine.c utils.c
DIRSRCS = src/
SRCS = ${addprefix ${DIRSRCS},${FL_SRCS}}

FL_OBJS = ${FL_SRCS:.c=.o}
DIROBJS = obj/
OBJS = ${addprefix ${DIROBJS},${FL_OBJS}}

INCLUDE = ./philo.h

### (EXPLICIT) RULES ###
${DIROBJS}%.o: ${DIRSRCS}%.c
	@echo "${YELLOW}Compiling:${WHITE} $< ${DEF_COLOR}"
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -I {INCLUDE} -o ${NAME}
	@echo "Rule '${GREEN}all${DEF_COLOR}' for mandatory ${NAME} executed successfully!"

clean:
	${RM} ${OBJS}
	@echo "Rule '${GREEN}clean${DEF_COLOR}' for ${NAME} executed successfully!"

fclean:
	${RM} ${OBJS} ${NAME} ${NAME_BONUS}
	@echo "Rule '${GREEN}fclean${DEF_COLOR}' for ${NAME} executed successfully!"

re:	fclean all
	@echo "Rule '${GREEN}re${DEF_COLOR}' for ${NAME} executed successfully!"

### (BRIGHT) COLORS ###

DEF_COLOR = \033[0;39m
BLACK = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[0;97m
