# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 20:33:41 by jvacaris          #+#    #+#              #
#    Updated: 2021/09/22 20:33:43 by jvacaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	mandatory/fdf.c \
		mandatory/inputs.c \
		mandatory/calculatepoints.c \
		mandatory/makinglines.c \
		mandatory/key_pressed.c \

SRCS_BONUS =	bonus/fdf_bonus.c \
				bonus/inputs_bonus.c \
				bonus/calculatepoints_bonus.c \
				bonus/makinglines_bonus.c \
				bonus/key_pressed_bonus.c \

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

PATH_INCLUDES = ./includes/
PATH_MLX = ./mlx/
PATH_LIBFT = ./libftjvb/
PATH_MANDATORY = ./mandatory/
PATH_BONUS = ./bonus/
PATH_MLX = ./mlx/

NAME = fdf
NAME_BONUS = fdf_bonus
LIBFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
SUFFIX = -lmlx -framework OpenGL -framework AppKit

all:		${NAME}
${NAME}:	${OBJS} ${LIBFT} ${MLX}
			${CC} ${CFLAGS} libft/${LIBFT} ${OBJS} -I ${PATH_LIBFT} -I ${PATH_INCLUDES} -I ${PATH_MLX} ${SUFFIX} -o ${NAME}
${LIBFT}:	
			@make -C ${PATH_LIBFT}
${MLX}:
			@make -C ${PATH_MLX}

bonus:			${NAME_BONUS}
${NAME_BONUS}:	${OBJS_BONUS} ${LIBFT} ${MLX}
				${CC} ${CFLAGS} libftjvb/${LIBFT} ${OBJS_BONUS} -I ${PATH_LIBFT} -I ${PATH_INCLUDES} -I ${PATH_MLX} ${SUFFIX} -o ${NAME_BONUS}

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@make clean -C ${PATH_LIBFT}
	@make clean -C ${PATH_MLX}
	@echo ".o's are no more!"
fclean:		clean
	@${RM} ${NAME} ${NAME_BONUS} libftjvb/${LIBFT}
	@echo "(including .a's and fdf*)"
re:		fclean all
rebonus:		fclean bonus
.PHONY: all clean fclean re
