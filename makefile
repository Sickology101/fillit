# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marius <marius@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 14:35:22 by marius            #+#    #+#              #
#    Updated: 2022/01/11 14:37:38 by marius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./fillit/.c
OBJS = ./fillit/.o
HDR = ./fillit/fillit.h 
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME):
    make -C $(LIBFT)
    gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean: 
    /bin/rm -f $(OBJS)
    make -C $(LIBFT) clean

fclean: clean
    /bin/rm -f $(NAME)
    make -C $(LIBFT) fclean

re: fclean all