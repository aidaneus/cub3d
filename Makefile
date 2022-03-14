NAME = cub3D
NAME_BONUS = cub3D
CC = gcc $(CFLAGS)
CFLAGS = -g -Wall -Wextra -Werror
MLX = ./opengl
MLX2 = -framework OpenGL -framework AppKit $(MLX_NAME)
HEADER = -I includes/
MLX_NAME = libmlx.a
SRC = cub3d \
	ft_bmp \
	ft_check \
	ft_color \
	ft_exit \
	ft_list_utils \
	ft_move \
	ft_parse \
	ft_parse2 \
	ft_raycast \
	ft_rays \
	ft_read \
	ft_sprite \
	ft_sprite2 \
	ft_texture \
	ft_utils \
	ft_utils2 \
	ft_validation \
	get_next_line \
	get_next_line_utils \

HEADER_BONUS = -I bonus/includes/
FIL = $(addsuffix .c, $(addprefix src/, $(SRC)))
OBJ = $(FIL:.c=.o)
BIN = $(addsuffix .o, $(SRC))

SRC_BONUS = cub3d_bonus \
		ft_bmp_bonus \
		ft_check_bonus \
		ft_color_bonus \
		ft_exit_bonus \
		ft_list_utils_bonus \
		ft_move_bonus \
		ft_parse_bonus \
		ft_parse2_bonus \
		ft_raycast_bonus \
		ft_rays_bonus \
		ft_read_bonus \
		ft_sprite_bonus \
		ft_sprite2_bonus \
		ft_texture_bonus \
		ft_utils_bonus \
		ft_utils2_bonus \
		ft_validation_bonus \
		get_next_line_bonus \
		get_next_line_utils_bonus \

FIL_BONUS = $(addsuffix .c, $(addprefix bonus/src_bonus/, $(SRC_BONUS)))
OBJ_BONUS = $(FIL_BONUS:.c=.o)
BIN_BONUS = $(addsuffix .o, $(SRC_BONUS))


.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) 
	@echo "\n\033[0;33mCompiling..."
	@make -C $(MLX)
	@mv opengl/$(MLX_NAME) .
	@$(CC) -o $(NAME) $(OBJ) $(MLX2)
	@echo "\033[0m"

bonus:  $(OBJ_BONUS) 
	@make -C $(MLX)
	@mv opengl/$(MLX_NAME) .
	@$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(MLX2)
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	@rm -rf $(OBJ) $(B_OBJ)
	@rm -rf $(OBJ_BONUS)
	@make clean -C $(MLX)
	@rm -f screen.bmp
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	@rm -f $(MLX_NAME) 
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "\033[0m"

re: fclean all