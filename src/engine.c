/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:28 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/22 19:46:37 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &x, &y);
	data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &x, &y);
	data->c_exit = mlx_xpm_file_to_image(data->mlx, C_EXIT, &x, &y);
	data->o_exit = mlx_xpm_file_to_image(data->mlx, O_EXIT, &x, &y);
	data->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &x, &y);
	data->playerdoor = mlx_xpm_file_to_image(data->mlx, PLAYERDOOR, &x, &y);
	data->f_faith = mlx_xpm_file_to_image(data->mlx, FIND_FAITH, &x, &y);
	if (!data->wall || !data->floor || !data->collect || !data->c_exit
		|| !data->o_exit || !data->player || !data->playerdoor
		|| !data->f_faith)
		return (ft_clean_and_exit(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
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

void	render(t_data *data)
{
	if (data->map[data->j][data->i] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->c_exit,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'E' && data->col == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->o_exit,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P' && data->flg == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->playerdoor,
			data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P' && data->col == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->f_faith,
			data->i * 64, data->j * 64);
}

int	loop(t_data *data)
{
	while (data->map[data->j])
	{
		data->i = 0;
		while (data->map[data->j][data->i])
		{
			render(data);
			data->i++;
		}
		data->j++;
	}
	data->j = 0;
	return (0);
}

int	ft_init_game(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, (data->len_x + 1) * 64,
			data->len_y * 64, "The Binding of Issac");
	if (data->mlx_win == NULL)
		ft_clean_and_exit(data);
	if (init_image(data))
		ft_clean_and_exit(data);
	mlx_hook(data->mlx_win, 17, 0L, exit_game, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
