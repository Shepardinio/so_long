/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:31:47 by mel-yand          #+#    #+#             */
/*   Updated: 2024/02/22 17:59:30 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "./so_long.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		return (printf("Error, too much arguments\n"), -1);
	init_data(&data);
	ft_parsing(&data, argv[1]);
}