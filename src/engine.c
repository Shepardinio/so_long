/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/11 16:07:37 by mel-yand         ###   ########.fr       */
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
	if (keycode == 65307)
		mlx_destroy_window(data->mlx, data->mlx_win);
	else if (keycode == 119)
		printf("W\n");
	else if (keycode == 97)
		printf("A\n");
	else if (keycode == 115)
		printf("S\n");
	else if (keycode == 100)
		printf("D\n");
	return (0);
}

int	ft_init_game(t_data *data)
{
	int i = 0;
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
	
	while (i < 500)
	{
		my_mlx_pixel_put(data, i, i, 0x00FFFF00);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 2, 1L<<0, handle_keypress, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
