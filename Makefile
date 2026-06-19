# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 20:00:40 by juan-her          #+#    #+#              #
#    Updated: 2026/06/19 21:21:20 by lgrigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

LIBFT_DIR	= ./externals/libft
MLX_DIR		= ./externals/minilibx-linux

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) \
				-O3 -g3

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


PARSER_SRCS =  get_next_line.c parse_line_list_utils.c parser.c parser_check.c parser_color.c parser_header_b.c parser_header.c parser_header_utils.c parser_line_list.c parser_map.c parser_utils.c parser_validate_map_chars.c parser_validate_map_flood.c 
ENGINE_SRCS = calc_wall.c engine.c engine_create.c engine_move.c ray.c
PLAYER_SRCS =  player.c
SCREEN_SRCS = textures.c screen.c screen_life_cycle.c

SRCS		= $(addprefix $(SRC_DIR)/, main.c) \
			  $(addprefix $(SRC_DIR)/parser/, $(PARSER_SRCS)) \
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
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Objects delete"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(NAME)
	@echo "Cub3d delete"

re: fclean all

.PHONY: all clean fclean re
