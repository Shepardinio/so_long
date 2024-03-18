/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:07:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/18 17:59:24 by mel-yand         ###   ########.fr       */
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

void	ft_clean_and_exit(t_data *data)
{
	if (data->map != NULL)
		free_map(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor != NULL)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->collect != NULL)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->c_exit != NULL)
		mlx_destroy_image(data->mlx, data->c_exit);
	if (data->o_exit != NULL)
		mlx_destroy_image(data->mlx, data->o_exit);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->f_faith != NULL)
		mlx_destroy_image(data->mlx, data->f_faith);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}

int	ft_clean_and_return(t_data *data)
{
	if (data->map != NULL)
		free_map(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor != NULL)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->collect != NULL)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->c_exit != NULL)
		mlx_destroy_image(data->mlx, data->c_exit);
	if (data->o_exit != NULL)
		mlx_destroy_image(data->mlx, data->o_exit);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->f_faith != NULL)
		mlx_destroy_image(data->mlx, data->f_faith);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (0);
}