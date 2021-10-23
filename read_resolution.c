/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:50:54 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 18:16:44 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	read_resolution(char *s, t_mlx *mlx, t_check_params *ch)
{
	if (ch->screen_done)
		ft_put_error("U cant gimme the resolution twice!\n", mlx);
	ch->screen_done = 1;
	while (*s == ' ')
		s++;
	mlx->win.width = atoi(s);
	while (*s <= '9' && *s >= '0')
		s++;
	if (*s != ' ')
		ft_put_error("Mkynsh space bin Height w width!\n", mlx);
	while (*s == ' ')
		s++;
	mlx->win.height = atoi(s);
	if ((mlx->win.width <= 0 || mlx->win.width > 2560))
		mlx->win.width = 2560;
	if ((mlx->win.height <= 0 || mlx->win.height > 1440))
		mlx->win.height = 1440;
	test_param(s, mlx, "ash had tkhwira fi Resolution?");
}
