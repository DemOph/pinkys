/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:53:17 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/13 18:59:46 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int		which_param(char c, char *str, t_mlx *mlx, t_check_params *ch)
{
	//skip_space(str);
	while (*str == ' ')// || *str == '\n')
		str++;
	//printf("%c --\n", *str);
	if (c == 'R' && *(str + 1) == ' ')
		read_resolution(str + 1, mlx, ch);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_path(1, str + 2, mlx, ch);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_path(2, str + 2, mlx, ch);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		read_path(3, str + 2, mlx, ch);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		read_path(4, str + 2, mlx, ch);
	else if (c == 'F' && *(str + 1) == ' ')
		read_cf_color(str + 1, ch, mlx, 'f');
	else if (c == 'C' && *(str + 1) == ' ')
		read_cf_color(str + 1, ch, mlx, 'c');
	else if (c == '1' || c == ' ')
		return (0);
	else if (c)
			ft_put_error("Map contains caracters i shouldnt find in a Map!\n", mlx);
	return (1);
}
