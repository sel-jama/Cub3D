# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 15:57:00 by sel-jama          #+#    #+#              #
#    Updated: 2023/12/22 22:52:19 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parse/main.c execute/move.c execute/utils.c execute/castrays.c execute/render.c \
		parse/get_next_line/get_next_line.c parse/get_next_line/get_next_line_utils.c \
		Parse/Parse_funs.c Parse/Parse_sec_funs.c Parse/Parse_third_funs.c \
		execute/init.c execute/player.c execute/cub.c execute/minimap.c execute/cast_utils.c \

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
NAME = cub3d

HEADER = execute/cub3d.h

all: ${NAME}

${NAME} : ${OBJS} ${HEADER}
	@make -C libft/
	${CC} ${CFLAGS}  ${OBJS} -lmlx -framework OpenGL -framework AppKit libft/libft.a -o ${NAME}

clean :
	@rm -f ${OBJS}
	@make clean -C libft/

fclean : clean
	@rm -f ${NAME}
	@make fclean -C libft/

re : fclean all