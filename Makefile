NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT = lib/libft.a
SRC_DIR = ./src
SRC :=	main.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR = obj
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	@printf "\e[32mSo Long OK\e[0m\n"

$(NAME): $(OBJ)
	@$(MAKE) -C lib
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 

norminette:
	norminette $(SRC_DIR)
	norminette lib
	norminette ./include/

clean:
	@$(MAKE) -C lib clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C lib fclean
	@rm -f $(NAME)

re: fclean all