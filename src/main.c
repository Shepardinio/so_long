/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:31:47 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/27 18:25:31 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *data)
{
	data->map = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	if (argc != 2)
		return (printf("Error\ntoo much arguments\n"), -1);
	init_data(&data);
	err = ft_parsing(&data, argv[1]);
	if (err)
		return (print_err(err), -1);
	free_map(&data);
	return (printf("GOOD\n"), 0);
}
