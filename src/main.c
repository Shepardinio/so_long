/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:31:47 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/20 19:18:57 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->map_copy = NULL;
	data->mlx_win = NULL;
	data->y = 0;
	data->x = 0;
	data->i = 0;
	data->j = 0;
	data->len_y = 0;
	data->len_x = 0;
	data->col = 0;
	data->play = 0;
	data->ext = 0;
	data->flg = 0;
	data->wall = NULL;
	data->floor = NULL;
	data->collect = NULL;
	data->c_exit = NULL;
	data->o_exit = NULL;
	data->player = NULL;
	data->playerdoor = NULL;
	data->f_faith = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	if (argc != 2)
		return (printf("Error\ntoo much arguments\n"), -1);
	init_data(&data);
	err = ft_parsing(&data, argv[1]);
	if (err)
		return (free_map(&data), print_err(err), -1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_clean_and_exit(&data), 0);
	ft_init_game(&data);
	ft_clean_and_return(&data);
	return (0);
}
