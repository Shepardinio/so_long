/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/15 18:16:52 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_image(t_data *data)
{
	if (data->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			data->img_width, data->img_height))
		return ();
	if (data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			data->img_width, data->img_height))
		return ();
	if (data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			data->img_width, data->img_height))
		return ();
	if (data->c_exit = mlx_xpm_file_to_image(data->mlx, C_EXIT,
			data->img_width, data->img_height))
		return ();
	if (data->o_exit = mlx_xpm_file_to_image(data->mlx, O_EXIT,
			data->img_width, data->img_height))
		return ();
	if (data->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			data->img_width, data->img_height))
		return ();
	if (data->f_faith = mlx_xpm_file_to_image(data->mlx, FIND_FAITH,
			data->img_width, data->img_height))
		return ();
	return (EXIT_SUCCESS);
}