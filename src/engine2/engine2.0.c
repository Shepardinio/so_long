/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:08:26 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/25 17:09:40 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_game2(t_data *data)
{
	data->win_width = (data->len_x + 1) * 64;
	data->win_height = data->len_y * 64;
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "The Binding of Issac");
	if (data->mlx_win == NULL)
		ft_clean_and_exit(data);
	data->mlx_img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (data->mlx_img == NULL)
		ft_clean_and_exit(data);
	data->mlx_img->data = mlx_get_data_addr(data->mlx_img,
			&(int){0}, &(int){0}, &(int){0});
	if (init_image2(data))
		ft_clean_and_exit(data);
	mlx_hook(data->mlx_win, 17, 0L, exit_game, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
