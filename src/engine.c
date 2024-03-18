/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/18 18:07:26 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
}

int	handle_keypress(int keycode, t_data *data)
{

	
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keycode == XK_w)
		move_top(data);
	else if (keycode == XK_a)
		move_left(data);
	else if (keycode == XK_s)
		move_down(data);
	else if (keycode == XK_d)
		move_right(data);
	return (0);
}

int	exit_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	loop(t_data *data)
{
	while (data->map[data->j])
	{
		data->i = 0;
		while (data->map[data->j][data->i])
		{
			if (data->map[data->j][data->i] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->c_exit, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == 'E' && data->col == 0)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->o_exit, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->i * 64, data->j * 64);
			if (data->map[data->j][data->i] == 'P' && data->col == 0)
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->f_faith, data->i * 64, data->j * 64);
			data->i++;
		}
		data->j++;
	}
	data->j = 0;
	return (0);
}

int	ft_init_game(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, (data->len_x + 1) * 64, data->len_y * 64, "./so_long");
	if (data->mlx_win == NULL)
		ft_clean_and_exit(data);
	if (init_image(data))
		ft_clean_and_exit(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_hook(data->mlx_win, 17, 0L, exit_game, data);
	mlx_hook(data->mlx_win, 2, 1L<<0, handle_keypress, data);
	mlx_loop(data->mlx);
	
	return (EXIT_SUCCESS);
}
