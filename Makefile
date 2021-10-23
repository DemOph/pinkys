# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 11:00:01 by chael-ha          #+#    #+#              #
#    Updated: 2021/10/22 15:14:52 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

MINILIBX = -lmlx -framework OpenGL -framework AppKit
SRC		= readmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_atoi.c \
		ft_init_params.c \
		ft_put_error.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		my_mlx_pixel_put.c \
		main.c \
		ft_exit.c \
		verify_params.c \
		read_path.c \
		test_param.c \
		read_resolution.c \
		read_rgb.c \
		which_param.c \
		read_cf_color.c \
		get_map_lines.c \
		countx.c \
		county.c \
		manage_player.c \
		vector_2d_manip.c \

OBJ = $(SRC:.c=.o)
		
DEPS = structs.h \
	get_next_line/get_next_line.h \
	
# CFLAGS = -g -Wall -Werror -Wextra
CFLAGS = -g
CC = gcc
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(DEPS)	
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)

re: fclean all