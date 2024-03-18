/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/18 16:57:48 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &x, &y);
	data->c_exit = mlx_xpm_file_to_image(data->mlx, C_EXIT, &x, &y);
	data->o_exit = mlx_xpm_file_to_image(data->mlx, O_EXIT, &x, &y);
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
	data->f_faith = mlx_xpm_file_to_image(data->mlx, FIND_FAITH, &x, &y);
	if (!data->wall || !data->floor || !data->collect || !data->c_exit ||
		!data->o_exit || !data->player || !data->f_faith)
		return (ft_clean_and_exit(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
