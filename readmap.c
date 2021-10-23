/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:48:08 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 15:29:06 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	skip_space(char *s)
{
	while (*s == ' ')
		s++;
}

char    **parse_param(t_mlx *mlx, char **lines, t_check_params *ch)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (lines[i] && lines[i][j] == ' ')
        j++;
    while(lines[i])
    {
		
        if (!(which_param(*lines[i], lines[i], mlx, ch)))
			return (&lines[i]);
		i++;    
    }
    ft_put_error("YA NO MAP IS FOUND, but wait how did ya even access this function?", mlx);
    return(lines);
}


void	check_map( t_mlx *mlx)//DONE_checks_for weird chars in original map
{
	int i;
	int j;
	char **map;
	
	i = 0;
	map = mlx->virgin_map;
	while (map[i] && i < mlx->max_y)
	{
		j = 0;
		while (map[i][j] && j < mlx->max_x)
		{
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' 
			&& map[i][j] != 'W' && map[i][j] != '1' && map[i][j] != '0' 
			&& map[i][j] != ' ')
			{
				// printf("hi\n");
				// printf("here %d\n", mlx->max_x);
				printf("[ -%c- ], i=%d, j=%d\n",  map[i][j], i, j);
				ft_put_error("map contain weird characters!", mlx);
			}
			j++;
		}
		i++;
	}
}

void		check_map_spaces(t_mlx* mlx, int i, int j)
{
	char **map;

	map = mlx->map_had6; 
	// printf("here |%d|\n", j);
	//printf("here %d\n%d\n", mlx->max_x, i);
	if ((j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != 'Q')
		|| (j+1 < mlx->max_x && map[i][j + 1] != '1' && map[i][j + 1] != 'Q')
	 	|| (i > 0 && map[i - 1][j] != '1' && map[i - 1][j] != 'Q')
	 	||(i+1 < mlx->max_y && map[i + 1][j] != '1' && map[i + 1][j] != 'Q'))
			{
				//printf("here %d", mlx->max_y);
				//printf("i = %d et j=%d et map[i][j]=%c\n", i, j, map[i][j]);
				ft_put_error("Spaces in map arent surrounded byyyy walls!\n", mlx);
			}
}

void	check_first_last_line(t_mlx *mlx, int i)
{
	int j;
	char **map;

	j = 0;
	map = mlx->map_had6;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != 'Q')
		{
			//printf("%c-*-", map[i][j]);
			ft_put_error("last or first line of map isnt cloosed", mlx);
		}//check first/last line
		if (map[i][j] == 'Q')
			check_map_spaces(mlx, i, j);
		j++;
	}	
}

void	check_first_last_column(t_mlx *mlx, int j)
{
	int i;
	char **map;

	i = 0;
	map = mlx->map_had6;
	while (map[i][j] && i < mlx->max_y - 1)
	{
		if (map[i][j] != '1' && map[i][j] != 'Q')
		{
			//printf("(%d, %d) %c\n", i, j, map[i][j]);
			ft_put_error("last or first column of map isnt cloosed", mlx);
		}//check first/last line
		if (map[i][j] == 'Q')
			check_map_spaces(mlx, i, j);
		i++;
	}	
}

void	fill_in_map_Q(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	// printf("ya hna %d", mlx->max_x);
	mlx->map_had6 = malloc((mlx->max_y) * sizeof(int *));
	while (i < mlx->max_y)
	{
		mlx->map_had6[i] = malloc((mlx->max_x) * sizeof(int));//wtf why does it only work with > 16
		j = 0;
		while (j < mlx->max_x)
		{
			mlx->map_had6[i][j] = 'Q';
			j++; 
		}
		mlx->map_had6[i][j] = '\0';
		i++;
	}
	//mlx->map_had6[i] = 0;
	// i = 0;
	// int b = mlx->max_x;
	// while (b--)
	// {
	// 	printf("%s\n", mlx->map_had6[i]);
	// 	i++;
	// }
	// printf("\nhere%d\n", mlx->max_x);
}

void	ismap_valid(t_mlx *mlx, t_check_params *ch)
{
	int i;
	int j;

	i = 0;

	check_map(mlx);//CHECK FOR WEIRD CHARS
	// exit(0);
	check_first_last_line(mlx, 0);
	check_first_last_column(mlx, 0);
	while (mlx->map_had6[i] && i < mlx->max_y)
	{
		j = 0;
		while (mlx->map_had6[i][j] && j < mlx->max_x)
		{
			// printf("i=%d -- j=%d ", i, j);
			//printf("%c ", mlx->map_had6[i][j]);
			if (mlx->map_had6[i][j] == 'Q' && j < mlx->max_x)
			{
				check_map_spaces(mlx, i, j);
			}
			j++;
			// else if (mlx->map_had6[i][mlx->max_y - 1] != '1')
			// {
			// 	printf("\ni=%d, j=%d-here--%s\n", i, j, mlx->map_had6[i]);
			// 	ft_put_error("map isnt closed!\n", mlx);
			// }
		}
		//printf("\n");
		i++;
	}
// //left to check last chars in virgin map
	manage_player(mlx, ch);
	check_first_last_column(mlx, mlx->max_x - 1);
	check_first_last_line(mlx, mlx->max_y - 1);
	
}

void	matching_maps(t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char **map;

	x = 0;
	i = -1;
	map = mlx->virgin_map;
	while (map[++i])
	{
		j = 0;
		y = 0;
		while (map[i][j])
		{
			
			while (map[i][j] == ' ')
			{
				j++;
				y++;
			}
			// printf("%d\n", x);
			// write(1, &mlx->map_had6[x][y], 7);
			if (map[i][j])
				mlx->map_had6[x][y++] = map[i][j++];
		}
		x++;
	}
	// i = 0;
	// int b = mlx->max_x;
	// printf("%d\n", b);
	// while (b--)
	// {
	// 	printf("%d --- %s\n", i, mlx->map_had6[i]);
	// 	i++;
	// }
}

void	check_last_char_in_line(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (mlx->virgin_map[i])
	{
		j = 0;
		while (mlx->virgin_map[i][j] != '\0' && mlx->virgin_map[i][j])
			j++;
		if (mlx->virgin_map[i][j - 1] == '0')
			ft_put_error("Map lines ends with 0!\n", mlx);
		i++;
	}
}

char** readmap(char *filename, t_mlx *mlx, t_check_params *ch)
{
    int     fd;
    char    **tmp;
	
	tmp = NULL;
    if((fd = open(filename, O_RDONLY)) < 0)
        ft_put_error("MAP FILE IS NOWHERE TO BE FOUND", mlx);
	mlx->lines = get_map_lines(mlx->lines, tmp, fd);
    close(fd);
    ft_init_params(mlx, ch);
    mlx->virgin_map = parse_param(mlx, mlx->lines, ch);
	check_last_char_in_line(mlx);
	verify_params(mlx, ch);
	mlx->max_x = countx(mlx);
	mlx->max_y = county(mlx);
	fill_in_map_Q(mlx);
	matching_maps(mlx);
	ismap_valid(mlx, ch);
	int i = 0;
	while(mlx->virgin_map[i] && i < mlx->max_x)
	{
		printf("%s|%d\n", mlx->virgin_map[i], i);
		i++;
	}
	return(mlx->virgin_map);
}