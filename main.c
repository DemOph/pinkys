/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:31:23 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/23 17:28:33 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	game_loop(void *mlx/*, t_check_params *ch, int keycode*/)
{
	return 0;
}

void print_coor(t_coor index)
{
	printf("(%d, %d)", index.x, index.y);
}

typedef struct s_line
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;	
}				t_line;


static void		ft_draw_line(t_mlx *mlx, t_coor pti, t_coor ptf, int color)
{
	t_line	line;

	line.dx = abs(ptf.x - pti.x);
	line.dy = abs(ptf.y - pti.y);
	line.sx = (pti.x < ptf.x) ? 1 : -1;
	line.sy = (pti.y < ptf.y) ? 1 : -1;
	line.err = line.dx - line.dy;
	while (1)
	{
		mlx_pixel_put(mlx->win.mlx_ptr, mlx->win.win_ptr, pti.x, pti.y, color);
		if ((pti.x == ptf.x) && (pti.y == ptf.y))
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			pti.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pti.y += line.sy;
		}
	}
}


void	draw_squire(t_mlx *mlx, int size, t_coor index, int color)
{
	t_coor draw_index;
	
	draw_index.y = index.y * size;
	while (draw_index.y < index.y * size + size - 1)
	{
		draw_index.x = index.x * size;
		while (draw_index.x < index.x * size + size - 1)
		{
			my_mlx_pixel_put(&mlx->screen_img, draw_index.x, draw_index.y, color);
			draw_index.x++;
		}
		draw_index.y++;
	}
	mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
		mlx->screen_img.img, 0, 0);
}

void	draw_map(t_mlx *mlx)
{
	t_coor index;
	index.y = -1;
	while (mlx->virgin_map[++index.y])
	{
		index.x = -1;
		while (mlx->virgin_map[index.y][++index.x])
		{
			if (mlx->virgin_map[index.y][index.x] == '1')
				draw_squire(mlx, 42, index, 0x00FF00);
		}
	}
}

int	ft_move_player(t_mlx *mlx, int move_y, int move_x)
{
	mlx->player.player_coor.old_x = mlx->player.player_coor.x;
	mlx->player.player_coor.old_y = mlx->player.player_coor.y;

	if (mlx->map_had6[mlx->player.player_coor.y + move_y][mlx->player.player_coor.x + move_x] != '1')// && mlx->map_had6)
	{
		mlx->player.player_coor.x = mlx->player.player_coor.old_x + move_x;
		mlx->player.player_coor.y = mlx->player.player_coor.old_y + move_y;
		mlx->map_had6[mlx->player.player_coor.y][mlx->player.player_coor.x] = mlx->player.pos;
		draw_player(mlx);
		return (1);
	}
	return (0);
}

void	ft_clear_mlx(t_mlx *mlx)
{
	t_coor	resolution;

	mlx = &game_object->render_data.mlx;
	resolution = game_object->render_data.window_resolution;
	mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img.img_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win.win_ptr);
	mlx->mlx_img.img_ptr = mlx_new_image(
			mlx->mlx_ptr, resolution.x, resolution.y);
	mlx->mlx_img.img_data = (int *)
		mlx_get_data_addr(mlx->mlx_img.img_ptr, &mlx->mlx_img.bpp,
			&mlx->mlx_img.size_l, &mlx->mlx_img.endian);
}

int	key_press(int keycode, t_mlx *mlx, t_coor *player_coor)
{
	int k;

	k = 0;
	// printf("miaw\n");
	// printf("(%d, %d)\n",player_coor.y,player_coor.x);
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT_KEY)
		k = ft_move_player(mlx, 0, 1);
	if (keycode == DOWN_KEY)
		k = ft_move_player(mlx, 1, 0);
	if (keycode == UP_KEY)
		k = ft_move_player(mlx, -1, 0);
	if (keycode == LEFT_KEY)
		k = ft_move_player(mlx, 0, -1);
	if (k)
	{
		draw_map(mlx);
		
		mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
			mlx->screen_img.img, player_coor->old_y, player_coor->old_x);
	}
	return (0);
}

int close_game()
{
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_check_params ch;
	char	**s;
	if (argc > 2)
		ft_put_error("too much arguments\n", &mlx);
	s = readmap(argv[1], &mlx, &ch);
	if (!s)
		ft_put_error("Error reading the map!\n", &mlx);
	mlx.win.mlx_ptr = mlx_init();
	mlx.win.win_ptr = mlx_new_window(mlx.win.mlx_ptr, mlx.win.width,
			mlx.win.height, "./cub3D");
	mlx.screen_img.img = mlx_new_image(mlx.win.mlx_ptr, mlx.win.width,
	 		mlx.win.height);
	mlx.screen_img.addr = mlx_get_data_addr(mlx.screen_img.img,
			&mlx.screen_img.bits_per_pixel, &mlx.screen_img.line_length,
			&mlx.screen_img.endian);
	draw_map(&mlx);
	draw_squire(&mlx, 42, mlx.player.player_coor, 0xFF0000);
	// mlx_loop_hook(mlx.win.mlx_ptr, game_loop, &mlx);
	// mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_press, &mlx);
	// mlx_hook(mlx.win.win_ptr, 17, 1L << 5, close_game, &mlx);
	//printf("y=%d  |   x=%d\n",player_coor.old_y, player_coor.old_x);
	// mlx_hook(mlx.win.win_ptr, 17, 1L << 0, ft_exit, &mlx);
	mlx_loop(mlx.win.mlx_ptr);
}
