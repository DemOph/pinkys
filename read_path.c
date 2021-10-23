/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:48:49 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 20:44:38 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	read_path(int num, char *str, t_mlx *mlx, t_check_params *ch)
{
	while (*str == ' ')
		str++;
	if (num == 1)
	{
		mlx->w_no_text.relative_path = str;
		ch->no_tex_done = 1;
	}
	else if (num == 2)
	{
		mlx->w_so_text.relative_path = str;
		ch->so_tex_done = 1;
	}
	else if (num == 3)
	{
		mlx->w_we_text.relative_path = str;
		ch->we_tex_done = 1;
	}
	else if (num == 4)
	{
		mlx->w_ea_text.relative_path = str;
		ch->ea_tex_done = 1;
	}
}
