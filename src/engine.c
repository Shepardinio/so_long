/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/29 12:59:35 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	loop(t_data *data)
{
	char	*step;

	while (data->map[data->j])
	{
		data->i = 0;
		while (data->map[data->j][data->i])
		{
			render2(data);
			data->i++;
		}
		data->j++;
	}
	data->j = 0;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	step = ft_itoa(data->step_count);
	if (step == NULL)
		ft_clean_and_exit(data, E_MLX);
	mlx_string_put(data->mlx, data->mlx_win, 30, 30, 0xFFFFFFFF, step);
	free(step);
	return (0);
}

// void	render(t_data *data)
// {
// 	if (data->map[data->j][data->i] == '1')
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == '0')
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'C')
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'E')
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->c_exit,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'E' && data->col == 0)
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->o_exit,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'P')
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'P' && data->flg == 1)
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->playerdoor,
// 			data->i * 64, data->j * 64);
// 	if (data->map[data->j][data->i] == 'P' && data->col == 0)
// 		mlx_put_image_to_window(data->mlx, data->mlx_win, data->f_faith,
// 			data->i * 64, data->j * 64);
// }

// int	ft_init_game(t_data *data)
// {
// 	data->mlx_win = mlx_new_window(data->mlx, (data->len_x + 1) * 64,
// 			data->len_y * 64, "The Binding of Issac");
// 	if (data->mlx_win == NULL)
// 		ft_clean_and_exit(data, E_MLX);
// 	if (init_image2(data))
// 		ft_clean_and_exit(data, E_MLX);
// 	mlx_hook(data->mlx_win, 17, 0L, exit_game, data);
// 	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
// 	mlx_loop_hook(data->mlx, loop, data);
// 	mlx_loop(data->mlx);
// 	return (EXIT_SUCCESS);
// }
