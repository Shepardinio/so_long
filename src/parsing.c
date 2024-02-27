/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:55:08 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:48 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_line(char *av)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(av, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (i);
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
	int	line;
	int	fd;

	i = 0;
	line = count_line(av);
	data->map = malloc(sizeof(char *) * (line + 1));
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
	return (EXIT_SUCCESS);
}
