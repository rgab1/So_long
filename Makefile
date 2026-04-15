NAME		= so_long
CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
C_FLAGS		+= -Imlx
CPP_FLAGS	= -MMD

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= so_long.c \
			  Utils/parsing.c Utils/parsing_helper.c Utils/print_map.c \
			  Utils/print_square.c Utils/my_mlx_pixel_put.c \
			  Utils/key_handling.c Utils/moves.c Utils/checks.c Utils/print_assets.c

OBJ			= $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I . -I $(LIBFT_DIR) -I Utils -I$(LIBFT_DIR)/Print/Printf_utils/.

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    MLX_DIR    = mlx_linux
    LMLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
    INCLUDES   += -I/usr/include -Imlx_linux -O3
    MLX_EXEC   = libmlx_Linux.a
else
    MLX_DIR    = mlx
    LMLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
    INCLUDES   += -Imlx
    MLX_EXEC   = libmlx.dylib
endif

all: $(LIBFT) mlx_compile $(NAME)

-include $(DEPENDENCIES)

mlx_compile:
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX_EXEC) .

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) $(LMLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

do: all clean
	clear

fclean: clean
	rm -f $(NAME) $(MLX_EXEC)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re redo mlx_compile
