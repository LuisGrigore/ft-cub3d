# Nombre del ejecutable
NAME = program

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra
CPPFLAGS = -I$(MINILIBX_DIR)

# MiniLibX
MINILIBX_DIR = externals/minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_LDFLAGS = -L$(MINILIBX_DIR)
MINILIBX_LIBS = -lmlx_Linux -lXext -lX11 -lm -lz

# Código fuente del proyecto
SRC = $(shell find src -type f -name "*.c")
OBJ = $(SRC:.c=.o)

# Regla principal: compilar el programa
all: $(NAME)

$(NAME): $(MINILIBX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $@ $(MINILIBX_LDFLAGS) $(MINILIBX_LIBS)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

# Regla para compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJ)

# Limpiar todo (incluyendo el ejecutable)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean

# Recompilar desde cero
re: fclean all

# Evitar que make interprete los nombres de las reglas como archivos
.PHONY: all clean fclean re
