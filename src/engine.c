/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/15 17:37:21 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_keypress(int keycode, t_data *data)
{

	
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keycode == XK_w)
	{
		printf("W\n");
	}
	else if (keycode == XK_a)
	{
		printf("A\n");
	}
	else if (keycode == XK_s)
	{
		printf("S\n");
	}
	else if (keycode == XK_d)
	{
		printf("D\n");
	}
	return (0);
}

int	exit_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	loop(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 50)
	{
		i = 0;
		while (i < 50)
		{
			my_mlx_pixel_put(data, data->i + i, data->j + j, data->color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (E_MLX_INI);
	data->mlx_win = mlx_new_window(data->mlx, data->len_y * 64, data->len_x * 64, "./so_long");
	if (data->mlx_win == NULL)
		return (E_MLX_NW);
	if (init_image(data))
		return (1);
	data->img = mlx_new_image(data->mlx, 500, 500);
	if (data->img == NULL)
		return (E_MLX_NI);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 1L<<0, handle_keypress, data);
	mlx_hook(data->mlx_win, 17, 0L, &exit_game, data);
	
	mlx_loop_hook(data->mlx, &loop, data);
	mlx_loop(data->mlx);
	
	return (EXIT_SUCCESS);
}
