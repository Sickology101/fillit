/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:38:28 by marius            #+#    #+#             */
/*   Updated: 2022/01/20 02:21:12 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define START_NAME 'A'
# define MAX_TETRIMINOS 26
# define EMPTY_CHAR '.'
# define VALID_CHAR '#'

typedef struct s_node
{
	struct s_node			*up;
	struct s_node			*down;
	struct s_node			*left;
	struct s_node			*right;
	struct t_header_node	*header;
}							t_node;

typedef struct s_header_node
{
	struct s_node			base;
	char					*name;
	size_t					size;
}							t_header_node;

typedef struct s_row
{
	struct s_row			*down;
	struct s_row			*up;
	int						tetr[4][2];
	int						length;
	char					*name;
	struct s_row			*head;
}							t_row;

typedef struct s_solution
{
	t_header_node			base;
	t_header_node			*headers;
	t_node					*nodes;
	size_t					columns;
	size_t					rows;
}							t_solution;

typedef struct s_solution_row
{
	t_node					*row_node;
	char					*name;
}							t_solution_row;

void	solve(void);
void	read_to_array(int fd);
void	print_4_2_array(t_row *row);
int		chk_vld_add_stru(char *tetrimino, t_row **root);
int		chk_out_of_bounds(char *tetr);
int		chk_edges_connected(char *tetr, int nxn_size);
int		chk_vld_add_stru(char *tetrimino, t_row **root);
void	add_to_list(t_row *row, t_row **root);
void	error(int res);

#endif
