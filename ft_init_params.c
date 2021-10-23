/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:47:08 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 15:11:54 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void    ft_init_params(t_mlx *mlx, t_check_params *ch)
{
    ch->screen_done = 0;
    ch->floor_done = 0;
    ch->ceiling_done = 0;
    ch->no_tex_done = 0;
    ch->so_tex_done = 0;
    ch->ea_tex_done = 0;
    ch->we_tex_done = 0;
    ch->player_count = 0;
    ch->ceiling_color = 0;
    ch->floor_color = 0;
    mlx->player.player_coor.x = 0;
    mlx->player.player_coor.y = 0;
    mlx->player.orientation_ray.x = 0.0;
    mlx->player.orientation_ray.y = 0.66;
}
