# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weiyang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 14:50:58 by weiyang           #+#    #+#              #
#    Updated: 2025/07/24 14:51:00 by weiyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= .
SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(SRC:.c=.o)

MLX_DIR		= minilibx-linux
MLX_LIBS	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
INCLUDES	= -I$(MLX_DIR) -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIBS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
