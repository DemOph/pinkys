/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:29:58 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 13:14:34 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
