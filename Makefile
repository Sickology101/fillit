# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marius <marius@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:22 by marius            #+#    #+#              #
#    Updated: 2022/01/19 01:44:24 by severi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = includes/main.c \
		includes/readtoarray.c \
		includes/solve.c \
		includes/readfromfile.c \
		includes/add_to_list.c \
		includes/check_valid.c 
OBJS = includes/*.o
HDR = includes/fillit.h
LHDR = libft/
FLAGS = -Wall -Wextra -Werror
DFLAGS = -g -fsanitize=address -Wconversion

LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS)-I $(LHDR) $(HDR) -L. libft/libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

debug: fclean
	make -C $(LIBFT)
	gcc $(FLAGS) $(DFLAGS) -o $(NAME) $(SRCS)-I $(LHDR) $(HDR) -L. libft/libft.a
