/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:47:43 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 18:56:40 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	verify_params( t_mlx *mlx, t_check_params *ch)
{
	if (!(ch->screen_done))
		ft_put_error("NO RESOLUTION INPUT\n", mlx);
	if (!(ch->floor_done))
		ft_put_error("NO FLOOR COLOR INPUT\n", mlx);
	if (!(ch->ceiling_done))
		ft_put_error("NO CEILING COLOR INPUT\n", mlx);
	if (!ch->no_tex_done || !ch->so_tex_done || !ch->ea_tex_done ||
		!ch->we_tex_done)
		ft_put_error("MISSING TEXTUuuRE PATH\n", mlx);
}