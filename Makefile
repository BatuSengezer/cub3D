# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 11:18:15 by joschka           #+#    #+#              #
#    Updated: 2024/12/13 17:19:40 by jbeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3d
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror
LIBFT	:=	./libft

# Detect operating system
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    # macOS configuration
    LIBMLX	:= ./minilibx-macos
    LKMLX	:= -L $(LIBMLX) -lmlx -framework OpenGL -framework AppKit
else
    # Linux configuration
    LIBMLX	:= ./minilibx-linux
    LKMLX	:= -L $(LIBMLX) -lmlx -lX11 -lXext
endif

LKLIBFT	:=	-L $(LIBFT) -lft
LIBS	:=	$(LKMLX) $(LKLIBFT) -lm
HEADERS	:=	-I ./include \
			-I ../include \
			-I $(LIBMLX) \
			-I ./libft \

SRCS	:=	./src/main.c \
			./src/init.c \
			./src/parsing/parsing.c \
			./src/parsing/get_scene.c \
			./src/parsing/check_scene.c \
			./src/delete_and_error.c \
			./src/parsing/get_textures.c \
			./src/parsing/get_colors.c \
			./src/parsing/utils.c \
			./src/parsing/get_map.c \
			./src/parsing/check_map.c \
			./src/game/game.c \
			./src/game/debug.c \
			./src/game/utils.c \
			./src/game/player.c \
			./src/game/key_hooks.c \
			./src/game/raycasting.c \
			./src/game/minimap.c \
			./src/game/minimap_2.c \
			./src/parsing/check_xpm.c \
			./src/game/get_player.c \
			./src/init_2.c \
			./src/cleanup.c \
			./src/game/dda.c \

OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	make -C $(LIBMLX)

libft:
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIBMLX) clean
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft libmlx
