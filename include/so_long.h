/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:17:13 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/22 19:51:39 by mel-yand         ###   ########.fr       */
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
	E_INV_FMT = 1
};

typedef struct s_error
{
	enum e_error id;
	char 		*err_msg;
}t_error;

static t_error const g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nWrong format"}
}

#endif