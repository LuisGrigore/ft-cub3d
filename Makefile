# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 20:00:40 by juan-her          #+#    #+#              #
#    Updated: 2026/06/07 23:18:29 by lgrigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bandera

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

LIBFT_DIR	= ./externals/libft
MLX_DIR		= ./externals/minilibx-linux

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) \
				-O3 -g3 -Wno-cast-function-type

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# SRC FILES
PARSE_SRCS = init_parse.c parse.c header.c check_header.c map.c check_map.c final_parse.c
CLEAN_SRCS = clean_1.c
UTILS_FILE_SRC = get_next_line.c utils.c utils_map.c
ENGINE_SRCS = engine.c
PLAYER_SRCS = player.c
SCREEN_SRCS = screen.c

SRCS		= $(addprefix $(SRC_DIR)/, main.c) \
			  $(addprefix $(SRC_DIR)/parseo/, $(PARSE_SRCS)) \
			  $(addprefix $(SRC_DIR)/clean/, $(CLEAN_SRCS)) \
			  $(addprefix $(SRC_DIR)/utils/parse_file/, $(UTILS_FILE_SRC)) \
			  $(addprefix $(SRC_DIR)/game/engine/, $(ENGINE_SRCS)) \
			  $(addprefix $(SRC_DIR)/game/player/, $(PLAYER_SRCS)) \
			  $(addprefix $(SRC_DIR)/screen/, $(SCREEN_SRCS)) \

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

# ---------------- RULES ---------------- #

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "Bandera Negra done"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Objects delete"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Cub3d delete"

re: fclean all

.PHONY: all clean fclean re
