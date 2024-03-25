/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:39:59 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/25 15:04:16 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_addr(t_data *data)
{
	data->wall->data = mlx_get_data_addr(data->wall,
			&(int){0}, &(int){0}, &(int){0});
	data->floor->data = mlx_get_data_addr(data->floor,
			&(int){0}, &(int){0}, &(int){0});
	data->collect->data = mlx_get_data_addr(data->collect,
			&(int){0}, &(int){0}, &(int){0});
	data->c_exit->data = mlx_get_data_addr(data->c_exit,
			&(int){0}, &(int){0}, &(int){0});
	data->o_exit->data = mlx_get_data_addr(data->o_exit,
			&(int){0}, &(int){0}, &(int){0});
	data->player->data = mlx_get_data_addr(data->player,
			&(int){0}, &(int){0}, &(int){0});
	data->playerdoor->data = mlx_get_data_addr(data->playerdoor,
			&(int){0}, &(int){0}, &(int){0});
	data->f_faith->data = mlx_get_data_addr(data->f_faith,
			&(int){0}, &(int){0}, &(int){0});
}

int	init_image2(t_data *data)
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
	init_addr(data);
	if (!data->wall || !data->floor || !data->collect || !data->c_exit
		|| !data->o_exit || !data->player || !data->playerdoor
		|| !data->f_faith)
		return (ft_clean_and_exit(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->mlx_img->data;
	dst[y * data->win_width + x] = color;
}

void	my_put_image(t_data *data, t_img *img, int x, int y)
{
	int	img_x;
	int	img_y;
	int	color;

	img_y = 0;
	while (img_y < 64)
	{
		img_x = 0;
		while (img_x < 64)
		{
			color = ((int *)img->data)[img_x + img_y * 64];
			my_mlx_pixel_put(data, x + img_x, y + img_y, color);
			img_x++;
		}
		img_y++;
	}
}

void	render2(t_data *data)
{
	if (data->map[data->j][data->i] == '1')
		my_put_image(data, data->wall, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == '0')
		my_put_image(data, data->floor, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'C')
		my_put_image(data, data->collect, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'E')
		my_put_image(data, data->c_exit, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'E' && data->col == 0)
		my_put_image(data, data->o_exit, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P')
		my_put_image(data, data->player, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P' && data->flg == 1)
		my_put_image(data, data->playerdoor, data->i * 64, data->j * 64);
	if (data->map[data->j][data->i] == 'P' && data->col == 0)
		my_put_image(data, data->f_faith, data->i * 64, data->j * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
}
