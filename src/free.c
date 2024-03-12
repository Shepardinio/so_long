/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:07:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/12 14:48:52 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_map_copy(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_copy && data->map_copy[i])
		free(data->map_copy[i++]);
	free(data->map_copy);
}

void	ft_destroy_all(int err, t_data *data)
{
	(void)data;
	if (err == 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		write(1, "destroy_image\n", 14);
	}
	if (err <= E_MLX_NI)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		write(1, "destroy_display\n", 16);
	}
	if (err <= E_MLX_NW)
	{
		free(data->mlx);
		write(1, "free data\n", 10);
	}
}