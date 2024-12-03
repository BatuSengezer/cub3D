# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 11:18:15 by joschka           #+#    #+#              #
#    Updated: 2024/12/03 17:48:37 by jbeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3d
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror
LIBMLX	:=	./minilibx-linux
LIBFT	:=	./libft
LKLIBFT	:=	-L $(LIBFT) -lft
LKMLX	:=	-L $(LIBMLX) -lmlx -lX11 -lXext
LIBS	:=	$(LKMLX) $(LKLIBFT)
HEADERS	:=	-I ./include \
			-I ../include \
			-I ./minilibx-linux \
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