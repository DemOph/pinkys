/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:03:16 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/21 17:01:40 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// # include <fcntl.h>
// # include "get_next_line/get_next_line.h"
// # include <stdlib.h>
// # include <stdio.h>
// # include <mlx.h>
// #include <math.h>

// typedef struct	s_texture {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_texture;

void	my_mlx_pixel_put(t_texture *text, int x, int y, int color)
{
	char	*dst;

	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	t_texture	img;
// 	int drawstart = 20;
// 	int drawend = 30;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 100, 100);
// 	win = mlx_new_window(mlx, 100 , 100, "./cub3D");
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);

// 	while (drawstart < drawend)
// 	{
// 		my_mlx_pixel_put(&img, 50, drawstart, 0xFFFFFF);
// 		drawstart++;
// 	}	
// 	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
