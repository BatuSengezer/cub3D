# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joschka <joschka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 19:29:15 by jbeck             #+#    #+#              #
#    Updated: 2023/07/28 12:27:44 by joschka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

FLAG = -Wall -Wextra -Werror

CC = cc

AR = ar rc

RM = rm -f

SRC = 	get_next_line.c \
		get_next_line_utils.c \


OBJ = $(SRC:.c=.o)

%.o: %.c
		@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re