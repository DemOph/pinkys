/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cf_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:54:39 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 20:52:33 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_check_cf(t_check_params *ch, char type, int color)
{
	if (type == 'f')
	{
		ch->floor_color = color;
		ch->floor_done = 1;
	}
	else if (type == 'c')
	{
		ch->ceiling_color = color;
		ch->ceiling_done = 1;
	}
}

void	read_cf_color(char *s, t_check_params *ch, t_mlx *mlx, char type)
{
	int			color;
	int			i;

	i = 3;
	color = 0;
	if (ch->floor_done && type == 'f')
		ft_put_error("Multiple floor color inputs\n", mlx);
	if (ch->ceiling_done && type == 'c')
		ft_put_error("Multiple ceiling color inputs\n", mlx);
	color = read_rgb(s, mlx);
	//printf("color is ; %d\n", color);
	ft_check_cf(ch, type, color);
}
