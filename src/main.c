/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:31:47 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/29 12:59:24 by mel-yand         ###   ########.fr       */
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
	data->step_count = 0;
	data->wall = NULL;
	data->floor = NULL;
	data->collect = NULL;
	data->c_exit = NULL;
	data->o_exit = NULL;
	data->player = NULL;
	data->playerdoor = NULL;
	data->f_faith = NULL;
	data->mlx_img = NULL;
	data->win_width = 0;
	data->win_height = 0;
}

void	check_texture(t_data *data)
{
	if (data->wall == 0 || data->floor == 0 || data->collect == 0
		|| data->c_exit == 0 || data->o_exit == 0 || data->player == 0
		|| data->playerdoor == 0 || data->f_faith == 0)
	{
		ft_clean_and_exit(data, E_IMG_XPM);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	if (argc != 2)
		return (write(2, "Error\ntoo much arguments", 24), -1);
	init_data(&data);
	err = ft_parsing(&data, argv[1]);
	if (err)
		return (free_map(&data), print_err(err), -1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_clean_and_exit(&data, E_MLX), 0);
	ft_init_game2(&data);
	ft_clean_and_return(&data);
	return (0);
}
