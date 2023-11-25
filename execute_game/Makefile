# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 15:57:00 by sel-jama          #+#    #+#              #
#    Updated: 2023/11/25 18:01:30 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c move.c utils.c castrays.c render.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

all: ${NAME}

${NAME} : ${OBJS}
	@make -C ../libft/
	${CC} ${CFLAGS}  ${OBJS} -lmlx -framework OpenGL -framework AppKit ../libft/libft.a -o ${NAME}

clean :
	@rm -f ${OBJS}
	@make clean -C ../libft/

fclean : clean
	@rm -f ${NAME}
	@make fclean -C ../libft/

re : fclean all