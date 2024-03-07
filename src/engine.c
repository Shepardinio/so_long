/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/07 23:59:33 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_init_game(t_data *data)
{
	int i = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "Hello word");
	if (data->mlx_win == NULL)
		return ;
	data->img = mlx_new_image(data->mlx, 500, 500);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	
	while (i < 500)
	{
		my_mlx_pixel_put(data, i, i, 0x00FFFF00);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
		i++;
	}
	mlx_loop(data->mlx);
}