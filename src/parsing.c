/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:55:08 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/26 18:33:08 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_arg(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (len < 5)
		return (E_INV_FMT);
	else if (!(argv[len - 4] == '.' && argv[len - 3] == 'b'
			&& argv[len - 2] == 'e' && argv[len - 1] == 'r'))
		return (E_INV_FMT);
	return (EXIT_SUCCESS);
}

int	ft_parsing(t_data *data, char *argv)
{
	(void)data;
	if (check_arg(argv))
		return (E_INV_FMT);
	return (EXIT_SUCCESS);
}
