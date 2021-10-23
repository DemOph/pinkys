/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:37 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/12 17:43:58 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

char *	check_tmp(char **tmp, int j, char **lines)
{
	j = 0;
	if (tmp)
	{
		while (tmp[j])
		{
			lines[j] = tmp[j];
			j++;
		}
	}
	if (tmp)
		free(tmp);
	return (lines[j]);
}

char	**get_map_lines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 1;
	j = 0;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		tmp = lines;
		lines = malloc((i + 1) * sizeof(char *));
		lines[j] = check_tmp(tmp, j, lines);
		lines[j++] = s;
		lines[j] = NULL;
		i++;
	}
	return (lines);
}