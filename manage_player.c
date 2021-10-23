/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:11:50 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 15:13:54 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	manage_player(t_mlx *mlx, t_check_params *ch)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(mlx->map_had6[i] && i < mlx->max_y - 1)
	{
		j = 0;
		while (mlx->map_had6[i][j] && j < mlx->max_x - 1)
		{	
			if (mlx->map_had6[i][j] == 'N' || mlx->map_had6[i][j] == 'S' || mlx->map_had6[i][j] == 'E' 
				|| mlx->map_had6[i][j] == 'W' )
			{
				ch->player_count++;
				mlx->player.player_coor.x = j;
				mlx->player.player_coor.y = i;
			}
			if (ch->player_count > 1)
				ft_put_error("Player direction is set more than once!\n", mlx);
			j++;
		}
		i++;
	}
}