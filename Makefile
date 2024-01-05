# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 15:57:00 by sel-jama          #+#    #+#              #
#    Updated: 2024/01/05 19:08:00 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parse/main.c execute/move.c execute/utils.c execute/castrays.c execute/render.c \
		parse/get_next_line/get_next_line.c parse/get_next_line/get_next_line_utils.c \
		parse/Parse_funs.c parse/Parse_sec_funs.c parse/Parse_third_funs.c \
		execute/init.c execute/player.c execute/cub.c execute/cast_utils.c \
		execute/render_2.c parse/Parse_4.c  execute/load_needs.c execute/draw_fc.c\
		parse/Parse_5.c parse/main2.c parse/Parse_funs_2.c parse/Parse_third_fun2.c

OBJS = ${SRCS:.c=.o}

CFLAGS =  -Wall -Wextra -Werror

NAME = cub3D

all: ${NAME}

${NAME} : ${OBJS}
	@make -C libft/
	${CC} ${CFLAGS}  ${OBJS} -lmlx -framework OpenGL -framework AppKit libft/libft.a -o ${NAME}

clean :
	@rm -f ${OBJS}
	@make clean -C libft/

fclean : clean
	@rm -f ${NAME}
	@make fclean -C libft/

re : fclean all
