/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:28 by marius            #+#    #+#             */
/*   Updated: 2022/01/13 01:33:32 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "fillit/libft"
# define BUFF_SIZE 1
# define MAX_TETROMINO 26

typedef struct	s_node
{
	struct s_node			*up;
	struct s_node			*down;
	struct s_node			*left;
	struct s_node			*right;
	struct t_header_node	*header;
	//char			*name;
	//int			size;
}							t_node;

typedef struct	s_header_node
{
	struct t_node			base;
	char					*name;
	size_t					size;
	}						t_header_node;
/*
typedef	struct	s_header
{
	struct			*right;
	struct			*left;
}					t_header;
*/
typedef struct	s_solution
{
	t_header_node			base;
	t_header_node			*headers;
	t_node					*nodes;
	size_t					columns;
	size_t					rows;
}							t_solution;

typedef struct	s_solution_row
{
	t_node					*row_node;
	char					*name;
}

#endif
