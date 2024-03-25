/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:50:42 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/25 12:51:25 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_top(t_data *d)
{
	if (d->map[d->y - 1][d->x] == 'E' && d->col == 0)
		mlx_loop_end(d->mlx);
	else if (d->map[d->y - 1][d->x] != '1')
	{
		if (d->map[d->y - 1][d->x] != '1' && d->flg == 1)
		{
			if (d->map[d->y - 1][d->x] == 'C')
				d->col--;
			d->map[d->y - 1][d->x] = 'P';
			d->map[d->y][d->x] = 'E';
			d->y -= 1;
			d->flg = 0;
			d->step_count += 1;
			return ;
		}
		if (d->map[d->y - 1][d->x] == 'E')
			d->flg = 1;
		if (d->map[d->y - 1][d->x] == 'C')
			d->col--;
		d->map[d->y - 1][d->x] = 'P';
		d->map[d->y][d->x] = '0';
		d->y -= 1;
		d->step_count += 1;
	}
}

void	move_down(t_data *d)
{
	if (d->map[d->y + 1][d->x] == 'E' && d->col == 0)
		mlx_loop_end(d->mlx);
	else if (d->map[d->y + 1][d->x] != '1')
	{
		if (d->map[d->y + 1][d->x] != '1' && d->flg == 1)
		{
			if (d->map[d->y + 1][d->x] == 'C')
				d->col--;
			d->map[d->y + 1][d->x] = 'P';
			d->map[d->y][d->x] = 'E';
			d->y += 1;
			d->flg = 0;
			d->step_count += 1;
			return ;
		}
		if (d->map[d->y + 1][d->x] == 'E')
			d->flg = 1;
		if (d->map[d->y + 1][d->x] == 'C')
			d->col--;
		d->map[d->y + 1][d->x] = 'P';
		d->map[d->y][d->x] = '0';
		d->y += 1;
		d->step_count += 1;
	}
}

void	move_right(t_data *d)
{
	if (d->map[d->y][d->x + 1] == 'E' && d->col == 0)
		mlx_loop_end(d->mlx);
	else if (d->map[d->y][d->x + 1] != '1')
	{
		if (d->map[d->y][d->x + 1] != '1' && d->flg == 1)
		{
			if (d->map[d->y][d->x + 1] == 'C')
				d->col--;
			d->map[d->y][d->x + 1] = 'P';
			d->map[d->y][d->x] = 'E';
			d->x += 1;
			d->flg = 0;
			d->step_count += 1;
			return ;
		}
		if (d->map[d->y][d->x + 1] == 'E')
			d->flg = 1;
		if (d->map[d->y][d->x + 1] == 'C')
			d->col--;
		d->map[d->y][d->x + 1] = 'P';
		d->map[d->y][d->x] = '0';
		d->x += 1;
		d->step_count += 1;
	}
}

void	move_left(t_data *d)
{
	if (d->map[d->y][d->x - 1] == 'E' && d->col == 0)
		mlx_loop_end(d->mlx);
	else if (d->map[d->y][d->x - 1] != '1')
	{
		if (d->map[d->y][d->x - 1] != '1' && d->flg == 1)
		{
			if (d->map[d->y][d->x - 1] == 'C')
				d->col--;
			d->map[d->y][d->x - 1] = 'P';
			d->map[d->y][d->x] = 'E';
			d->x -= 1;
			d->flg = 0;
			d->step_count += 1;
			return ;
		}
		if (d->map[d->y][d->x - 1] == 'E')
			d->flg = 1;
		if (d->map[d->y][d->x - 1] == 'C')
			d->col--;
		d->map[d->y][d->x - 1] = 'P';
		d->map[d->y][d->x] = '0';
		d->x -= 1;
		d->step_count += 1;
	}
}

int	exit_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}
