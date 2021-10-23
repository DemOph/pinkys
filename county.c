/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   county.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:03:23 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 16:03:37 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int		county(t_mlx *mlx)
{
	int i;
	int j;
	char **lines;

	i = 0;
	lines = mlx->virgin_map;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!lines[i][j] && lines[++i])
			ft_put_error("Empty line in ur map", mlx);
		i++;
	}
	return (i);
}