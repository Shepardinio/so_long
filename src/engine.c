/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/14 14:48:16 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int const	g_color_tab[] = {
	0xFFF000,
	0xFF8FFF,
	0x008080,
	0x000080,
};

int	handle_keypress(int keycode, t_data *data)
{
	// static int index;
	
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keycode == XK_w)
	{
		data->j--;
		data->color = g_color_tab[0];
	}
	else if (keycode == XK_a)
	{
		data->i--;
		data->color = g_color_tab[1];
	}
	else if (keycode == XK_s)
	{
		data->j++;
		data->color = g_color_tab[2];
	}
	else if (keycode == XK_d)
	{
		data->i++;
		data->color = g_color_tab[3];
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

	// int	*iaddr = (int *)data->addr;
	i = 0;
	while (i < 500 * 500)
	{
		data->addr[i * 4] = 0xFF;
		data->addr[i * 4 + 1] = 0xFF;
		data->addr[i * 4 + 2] = 0xFF;
		data->addr[i * 4 + 3] = 0xFF;
		++i;
	}
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
	data->mlx_win = mlx_new_window(data->mlx, 500, 500, "Hello word");
	if (data->mlx_win == NULL)
		return (E_MLX_NW);
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
