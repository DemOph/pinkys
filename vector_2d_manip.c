/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2d_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:58:48 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 15:20:51 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_d_coor	ft_angle_to_2d_vector(double alpha)
{
	return (ft_normalise_vector_2d((t_d_coor){cos(alpha), sin(alpha)}));
}

t_d_coor	ft_add_vector_2d(t_d_coor vector2D, t_d_coor second_vector2D)
{
	vector2D.x += second_vector2D.x;
	vector2D.y += second_vector2D.y;
	return (vector2D);
}

t_d_coor	ft_sub_vector_2d(t_d_coor vector2D, t_d_coor second_vector2D)
{
	vector2D.x -= second_vector2D.x;
	vector2D.y -= second_vector2D.y;
	return (vector2D);
}

t_d_coor	ft_scale_vector_2d(t_d_coor vector2D, double scale)
{
	vector2D.x *= scale;
	vector2D.y *= scale;
	return (vector2D);
}

t_d_coor	ft_normalise_vector_2d(t_d_coor vector)
{
	double	norm;

	norm = sqrtf(pow(vector.x, 2) + pow(vector.y, 2));
	vector.x /= norm;
	vector.y /= norm;
	return (vector);
}