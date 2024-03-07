/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:07:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/07 19:10:05 by mel-yand         ###   ########.fr       */
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

void	ft_destroy_all(t_data *data)
{
	(void)data;
	// mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}