NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT = libft/libft.a
SRC_DIR = ./src
SRC :=	main.c\
		parsing.c\
		check_map.c\
		flood_fill.c\
		print.c\
		free.c\
		game.c\
		engine.c\
		engine2/engine2.0.c\
		engine2/engine2.1.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
LDFLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext -lm

all: $(NAME)
	@printf "\e[32mSo Long OK\e[0m\n"

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -f $(NAME)

re: fclean all