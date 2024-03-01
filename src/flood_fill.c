/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:34:26 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/01 15:05:32 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill(char **tab, t_data cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= cur.len_y || cur.x < 0
		|| cur.x >= cur.len_x || tab[cur.y][cur.x] != to_fill)
		return ;

	tab[cur.y][cur.x] = 'F';
	fill(tab, (t_data){cur.x - 1, cur.y}, to_fill);
	fill(tab, (t_data){cur.x + 1, cur.y}, to_fill);
	fill(tab, (t_data){cur.x, cur.y - 1}, to_fill);
	fill(tab, (t_data){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_data *data)
{
	fill(data->map_copy, *data, data->map_copy[data->y][data->x]);
}