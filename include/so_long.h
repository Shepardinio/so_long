/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:17:13 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/27 16:10:45 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft.h"

typedef struct s_data
{
	char	**map;
}t_data;

enum e_error
{
	E_INV_FMT = 1,
	E_GNL,
};

typedef struct s_error
{
	enum e_error	id;
	char			*err_msg;
}t_error;

static t_error const	g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
{.id = E_GNL, .err_msg = "Error\nProblem with gnl executin\n"},
};

void	print_err(enum e_error id);
int		ft_parsing(t_data *data, char *argv);
void	free_map(t_data *data);

#endif