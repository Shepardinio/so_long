/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:31:47 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/07 18:39:16 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_copy = NULL;
	data->y = 0;
	data->x = 0;
	data->len_y = 0;
	data->len_x = 0;
	data->col = 0;
	data->play = 0;
	data->ext = 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;
	int		err;

	if (argc != 2)
		return (printf("Error\ntoo much arguments\n"), -1);
	init_data(&data);
	err = ft_parsing(&data, argv[1]);
	if (err)
		return (free_map(&data), print_err(err), -1);
	ft_init_game(&data);
	// start_game(&data);
	ft_destroy_all(&data);
	free_map(&data);
	return (0);
}
