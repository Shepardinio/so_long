/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:17:13 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/29 16:14:43 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft.h"

typedef struct s_data
{
	char	**map;
	char	**map_copy;
	int		y;
	int		x;
	int		len_y;
	int		len_x;
	int		col;
	int		play;
	int		ext;
}t_data;

enum e_error
{
	E_INV_FMT = 1,
	E_GNL,
	E_TOO_SML,
	E_INV_MAP,
	E_MALLOC,
};

typedef struct s_error
{
	enum e_error	id;
	char			*err_msg;
}t_error;

static t_error const	g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
{.id = E_GNL, .err_msg = "Error\nProblem with gnl executing\n"},
{.id = E_TOO_SML, .err_msg = "Error\nMap too small\n"},
{.id = E_INV_MAP, .err_msg = "Error\nInvalid map\n"},
{.id = E_MALLOC, .err_msg = "Error\nProblem with malloc"},
};

void	print_err(enum e_error id);
int		ft_parsing(t_data *data, char *argv);
int		check_len_line(t_data *data);
int		check_wall(t_data *data);
int		check_elem(t_data *data);
int		check_nbelem(t_data *data);
int		ft_cpy_map(t_data *data);
void	flood_fill(char **tab, t_data data);
void	free_map(t_data *data);
void	free_map_copy(t_data *data);

#endif