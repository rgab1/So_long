NAME		= so_long
CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
C_FLAGS		+= -Imlx
CPP_FLAGS	= -MMD
LMLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= 

OBJ			= $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I . -I $(LIBFT_DIR) -I Utils

all: $(LIBFT) $(NAME)

-include : $(DEPENDENCIES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LMLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re redo
