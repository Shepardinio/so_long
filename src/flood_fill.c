/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:34:26 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/22 16:05:13 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_flood_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
				return (E_INV_MAP);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

static int	is_to_fill(char c, char const *to_fill)
{
	int	i;

	i = 0;
	while (to_fill[i])
	{
		if (c == to_fill[i])
			return (0);
		i++;
	}
	return (1);
}

static void	fill(t_data *data, int x, int y, char const *to_fill)
{
	if (y < 0 || y >= data->len_y || x < 0 || x >= data->len_x
		|| is_to_fill(data->map_copy[y][x], to_fill))
		return ;
	data->map_copy[y][x] = 'F';
	fill(data, x - 1, y, to_fill);
	fill(data, x + 1, y, to_fill);
	fill(data, x, y - 1, to_fill);
	fill(data, x, y + 1, to_fill);
}

int	flood_fill(t_data *data)
{
	char const	to_fill[] = "P0CE";

	fill(data, data->x, data->y, to_fill);
	if (check_flood_fill(data->map_copy))
		return (free_map_copy(data), E_INV_MAP);
	return (free_map_copy(data), EXIT_SUCCESS);
}
