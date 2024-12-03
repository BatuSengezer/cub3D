# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joschka <joschka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 14:39:14 by jbeck             #+#    #+#              #
#    Updated: 2023/12/08 08:50:32 by joschka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

CC = cc

AR = ar rc

RM = rm -f

GNL = get_next_line/gnl.a

SRC =	ft_atoi.c \
		ft_itoa.c \
		ft_lstsize.c \
		ft_printnbr.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_lstadd_back.c \
		ft_memchr.c \
		ft_printptr.c \
		ft_strdup.c \
		ft_strrchr.c \
		ft_calloc.c \
		ft_lstadd_front.c \
		ft_memcmp.c \
		ft_printstr.c \
		ft_striteri.c \
		ft_strtrim.c \
		ft_hexlen.c \
		ft_lstclear.c \
		ft_memcpy.c \
		ft_printuint.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_isalnum.c \
		ft_lstdelone.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_lstiter.c \
		ft_memset.c \
		ft_putendl_fd.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_isascii.c \
		ft_lstlast.c \
		ft_printchar.c \
		ft_putnbr_fd.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_lstmap.c \
		ft_printf.c \
		ft_putstr_fd.c \
		ft_strmapi.c \
		ft_isprint.c \
		ft_lstnew.c \
		ft_printhex.c \
		ft_split.c \
		ft_strncmp.c \
		ft_subsplit.c \
		ft_subsplit_utils.c \

OBJ = $(SRC:.c=.o)


%.o: %.c
		@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(GNL):
		@make -C get_next_line

$(NAME): $(GNL) $(OBJ)
		@cp $(GNL) $(NAME)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)
		@make -C get_next_line clean

fclean: clean
		@$(RM) $(NAME)
		@make -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re
