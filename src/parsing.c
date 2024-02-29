/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:55:08 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/29 17:47:58 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_nbelem(t_data *data)
{
	if (data->col == 0)
		return (E_INV_MAP);
	if (data->ext != 1)
		return (E_INV_MAP);
	if (data->play != 1)
		return (E_INV_MAP);
	return (EXIT_SUCCESS);
}

int	count_line(char *av)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (-1);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (close(fd), -2);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	close(fd);
	return (i);
}

int	get_map(t_data *data, char *av)
{
	int	i;
	int	fd;

	i = 0;
	data->len_y = count_line(av);
	if (data->len_y < 0)
		return (E_GNL);
	data->map = malloc(sizeof(char *) * (data->len_y + 1));
	if (data->map == NULL)
		return (E_GNL);
	fd = open(av, O_RDONLY);
	data->map[i] = get_next_line(fd);
	while (data->map[i] != NULL)
	{
		i++;
		data->map[i] = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_arg(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (len < 5)
		return (E_INV_FMT);
	else if (!(argv[len - 4] == '.' && argv[len - 3] == 'b'
			&& argv[len - 2] == 'e' && argv[len - 1] == 'r'))
		return (E_INV_FMT);
	return (EXIT_SUCCESS);
}

int	ft_parsing(t_data *data, char *argv)
{
	if (check_arg(argv))
		return (E_INV_FMT);
	if (get_map(data, argv))
		return (E_GNL);
	if (data->len_y >= 0 && data->len_y <= 2)
		return (E_TOO_SML);
	if (check_len_line(data))
		return (E_INV_MAP);
	if (check_wall(data))
		return (E_INV_MAP);
	if (check_elem(data))
		return (E_INV_MAP);
	if (check_nbelem(data))
		return (E_INV_MAP);
	if (ft_cpy_map(data))
		return (E_MALLOC);
	flood_fill(data->map, *data);
	free_map_copy(data);
	return (EXIT_SUCCESS);
}
