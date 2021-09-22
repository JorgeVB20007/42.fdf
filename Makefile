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

SRCS =	fdf.c \
		inputs.c \
		calculatepoints.c \
		makinglines.c \
		key_pressed.c \

SRCS_BONUS =	fdf_bonus.c \
				inputs_bonus.c \
				calculatepoints_bonus.c \
				makinglines_bonus.c \
				key_pressed_bonus.c \

GNL =	get_next_line_utils.c \
		get_next_line.c \

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
GNLO = ${GNL:.c=.o}

PATH_INCLUDES = ./includes/
PATH_GNL = ./gnl/
PATH_MLX = ./mlx/
PATH_LIBFT = ./libft/
PATH_MANDATORY = ./mandatory/
PATH_BONUS = ./bonus/

NAME = fdf
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = cc
RM = rm -f
MLX = /usr/local/include
CFLAGS = -Wall -Werror -Wextra
SUFFIX = -lmlx -framework OpenGL -framework AppKit

all:		${NAME}
${NAME}:	${OBJS}
			${CC} ${CFLAGS} -L {PATH_LIBFT}

${NAME_BONUS}:	${PATH_MLX} ${LIBFT_PATH}${LIBFT} ${GNL_PATH}${GNL} ${OBJS_BONUS}
			${CC} ${CFLAGS} -I ${MLX} ${LIBFT_PATH}${LIBFT} ${OBJS} -o ${NAME} -L ${MLX} ${SUFFIX}

${LIBFT}:	
			make -C ${LIBFT_PATH}
clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}
	@echo ".o's are no more!"
fclean:		clean
	@${RM} ${NAME} libft/${LIBFT}
	@echo "(including ./fdf!)"
re:		fclean all
.PHONY: all clean fclean re
