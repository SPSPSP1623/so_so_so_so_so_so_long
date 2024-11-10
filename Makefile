NAME = so_long
SRC = $(addprefix src/, main.c errors.c init.c libft.c parsing.c utils_parsing1.c utils_parsing2.c draw.c move.c end.c)
GNL_SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CCFLAGS = -Wall -Werror -Wextra

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(shell uname).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib/X11 -lm -lz -lX11 -lXext
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME):$(OBJ) $(GNL_OBJ) $(MLX_LIB)
	cc $(CCFLAGS) $^ $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

debug: $(OBJ) $(GNL_OBJ)
	cc $(CCFLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	cc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C mlx/

re: fclean all
