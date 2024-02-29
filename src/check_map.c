/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:54:44 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/29 17:37:05 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_cpy_map(t_data *data)
{
	int i;

	i = 0;
	data->map_copy = malloc(sizeof(char *) * (data->len_y + 1));
	if (data->map_copy == NULL)
		return (E_MALLOC);
	data->map_copy[data->len_y] = NULL;
	while (data->map[i] != NULL)
	{
		data->map_copy[i] = malloc(sizeof(char) * (data->len_x + 2));
		if (data->map_copy[i] == NULL)
			return (E_MALLOC);
		ft_strlcpy(data->map_copy[i], data->map[i], (data->len_x + 2));
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_elem2(t_data *data, int i, int j)
{
	if (data->map[j][i] != '0' && data->map[j][i] != '1'
		&& data->map[j][i] != 'C' && data->map[j][i] != 'E'
		&& data->map[j][i] != 'P')
		return (E_INV_MAP);
	else if (data->map[j][i] == 'C')
		data->col += 1;
	else if (data->map[j][i] == 'E')
		data->ext += 1;
	else if (data->map[j][i] == 'P')
	{
		data->play += 1;
		data->y = j;
		data->x = i;
	}
	return (EXIT_SUCCESS);
}

int	check_elem(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (i != data->len_x + 1)
		{
			if (check_elem2(data, i, j))
				return (E_INV_MAP);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		if (j == 0 || j == data->len_y - 1)
		{
			i = 0;
			while (i != data->len_x + 1)
			{
				if (data->map[j][i] != '1')
					return (E_INV_MAP);
				i++;
			}
		}
		else if (data->map[j][0] != '1' || data->map[j][data->len_x] != '1')
			return (E_INV_MAP);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	check_len_line(t_data *data)
{
	int	len_x;
	int	j;
	int	i;

	len_x = 0;
	j = 1;
	i = 0;
	while (data->map[0][len_x] != '\n')
		len_x++;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
			i++;
		if (i != len_x)
			return (E_INV_MAP);
		j++;
	}
	data->len_x = len_x - 1;
	return (EXIT_SUCCESS);
}
