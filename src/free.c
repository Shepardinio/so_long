/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:07:33 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/29 12:51:27 by mel-yand         ###   ########.fr       */
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

void	destroy_image(t_data *data)
{
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
	if (data->playerdoor != NULL)
		mlx_destroy_image(data->mlx, data->playerdoor);
	if (data->f_faith != NULL)
		mlx_destroy_image(data->mlx, data->f_faith);
}

void	ft_clean_and_exit(t_data *data, enum e_error id)
{
	if (data->map != NULL)
		free_map(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_image(data);
	if (data->mlx_img != NULL)
		mlx_destroy_image(data->mlx, data->mlx_img);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	print_err(id);
	exit (0);
}

int	ft_clean_and_return(t_data *data)
{
	if (data->map != NULL)
		free_map(data);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	destroy_image(data);
	if (data->mlx_img != NULL)
		mlx_destroy_image(data->mlx, data->mlx_img);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (0);
}
