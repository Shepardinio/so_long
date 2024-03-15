/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yand <mel-yand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:17:13 by mel-yand          #+#    #+#             */
/*   Updated: 2024/03/15 18:09:16 by mel-yand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

# define WALL "image/wall.xpm"
# define FLOOR "image/floor.xpm"
# define COLLECT "image/item.xpm"
# define C_EXIT "image/doorclose.xpm"
# define O_EXIT "image/exit.xpm"
# define PLAYER "image/azazel.xpm"
# define FIND_FAITH "image/angel.xpm"

typedef struct s_data
{
	void 	*mlx;
	void 	*mlx_win;
	void 	*img;
	int		img_width;
	int		img_height;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*c_exit;
	void	*o_exit;
	void	*player;
	void	*f_faith;
	char 	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;

	char 	**map;
	char 	**map_copy;
	int 	y;
	int 	x;
	int 	i;
	int 	j;
	int 	len_y;
	int 	len_x;
	int 	col;
	int 	play;
	int 	ext;
} t_data;

enum e_error
{
	E_INV_FMT = 1,
	E_GNL,
	E_TOO_SML,
	E_INV_MAP,
	E_MALLOC,
	E_MLX_NW,
	E_MLX_NI,
	E_MLX_INI,
};

typedef struct s_error
{
	enum e_error id;
	char *err_msg;
} t_error;

static t_error const g_error[] = {
	{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
	{.id = E_GNL, .err_msg = "Error\nProblem with gnl executing\n"},
	{.id = E_TOO_SML, .err_msg = "Error\nMap too small\n"},
	{.id = E_INV_MAP, .err_msg = "Error\nInvalid map\n"},
	{.id = E_MALLOC, .err_msg = "Error\nProblem with malloc"},
	{.id = E_MALLOC, .err_msg = "Error\nFail at mlx_new_window"},
	{.id = E_MLX_NI, .err_msg = "Error\nFail at mlx_new_image"},
	{.id = E_MLX_INI, .err_msg = "Error\nFail at mlx_init"},
};

void print_err(enum e_error id);
int ft_parsing(t_data *data, char *argv);
int check_len_line(t_data *data);
int check_wall(t_data *data);
int check_elem(t_data *data);
int check_nbelem(t_data *data);
int ft_cpy_map(t_data *data);
int flood_fill(t_data *data);
void free_map(t_data *data);
void free_map_copy(t_data *data);
void ft_destroy_all(int err, t_data *data);

int ft_init_game(t_data *data);

#endif