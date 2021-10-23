/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:02:04 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 15:27:38 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int 	countx(t_mlx *mlx)
{
	int i;
	int j;
	int max_y;
	char **lines;

	lines = mlx->virgin_map;
	i = 0;
	max_y = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
			j++;
		if (j > max_y)
			max_y = j;
		i++;
	}
	return (max_y);
}