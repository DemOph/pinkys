/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:51:57 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 15:52:30 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int		read_rgb(char *s, t_mlx *mlx)
{
	int r;
	int g;
	int b;
	
	while (*s == ' ')
		s++;
	r = ft_atoi(s);
	while (*s <= '9' && *s >= '0')
		s++;
	while (*s == ' ')
		s++;		
	if (*s != ',')
		ft_put_error("I found no comma between coloors!", mlx);
	else
		s++;
	while (*s == ' ')
		s++;	
	g = ft_atoi(s);
	while (*s <= '9' && *s >= '0')
		s++;	
	while (*s == ' ')
		s++;		
	if (*s != ',')
		ft_put_error("I found no comma between coloors!", mlx);
	else
		s++;
	while (*s == ' ')
		s++;	
	b = ft_atoi(s);
	while (*s <= '9' && *s >= '0')
		s++;	
	while (*s == ' ')
		s++;
	if (*s)
		ft_put_error("dfuk why u shitting there?", mlx);
	return(r << 16 | g << 8 | b);
}