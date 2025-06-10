# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 19:54:01 by elengarc          #+#    #+#              #
#    Updated: 2025/05/25 19:54:03 by elengarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -fsanitize=address -g

MLX_DIR		= ./minilibx
LIBFT_DIR	= ./libft

MLX_LIB		= $(MLX_DIR)/libmlx.a
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC			= fractol.c events.c main.c errors.c events2.c palettes.c sets.c atof.c
OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) \
		-L$(MLX_DIR) -L$(LIBFT_DIR) -framework OpenGL -framework AppKit

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


