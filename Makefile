NAME = game
CC = cc
SRC = src/main.c src/player.c src/engine.c src/screen_manager.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Iexternal/ft-lib -Iexternal/mlx
LDFLAGS = -L./external/mlx -lmlx -lXext -lX11 -lm -lz
LIBS = external/ft-lib/libft.a external/mlx/libmlx.a

.PHONY: all external clean fclean re

all: external $(NAME)

external: external/ft-lib/libft.a external/mlx/libmlx.a

external/ft-lib/libft.a:
	make -C external/ft-lib

external/mlx/libmlx.a:
	make -C external/mlx

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	make -C external/ft-lib clean
	make -C external/mlx clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
