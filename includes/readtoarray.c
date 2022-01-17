/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtoarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 04:46:52 by severi            #+#    #+#             */
/*   Updated: 2022/01/17 20:35:39 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int ft_strcountchr(char *str, char c)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int		chk_out_of_bounds(char *tetr)
{
	if (ft_strlen(tetr) != 16 || ft_strcountchr(tetr, '#') != 4
	|| ft_strcountchr(tetr, '.') != 12)
		return (0);
	return (1);
}

int		chk_connections_4_ways(char *tetr, int nxn_size, int i)
{
	int connections;

	connections = 0;
	if (i % nxn_size >= 1)
	{
		if (tetr[i+1] == '#')
			connections++;
	}
	if (i < (nxn_size - 1) * nxn_size)
	{
		if (tetr[i+nxn_size] == '#')
			connections++;
	}
	if (i % nxn_size != nxn_size && i != 0)
	{
		if (tetr[i-1] == '#')
			connections++;
	}
	if (i > nxn_size)
	{
		if (tetr[i-nxn_size] == '#')
			connections++;
	}
	return (connections);
}
// str = ".......####......"
// 
// ....
// .##.
// .##.
// ....
//
int		chk_edges_connected(char *tetr, int nxn_size)
{
	int i;
	int concs;

	i = -1;
	concs = 0;
	while (++i < nxn_size * nxn_size)
	{
		if (tetr[i] == '#')
			concs += chk_connections_4_ways(tetr, nxn_size, i);
	}
	return (concs);
}

/*
 * This function RIP ?
 *
void	match_to_tetrimino(char tetr_array[], char *tetr)
{
	int i;
	int j;
	char alphabet;

	i = -1
	j = 0;
	alphabet = 'A';
	while (++i < 26)
	{
		if (g_unique_tetrs[i] == tetr)
			tetr_array[j++] = alphabet++;
	}
}
*/

int		count_zeros_rows(char *tetrimino)
{
	int zero;
	int i;

	zero = 0;
	i = 0;
	while (tetrimino[i] != '#')
	{
		i++;
		if ((i + 1) % 4 == 0)
			zero++;
	}
	return (zero);
}

int		count_zeros_columns(char *tetrimino)
{
	int zero;
	int i;

	zero = 0;
	i = 0;
	while (tetrimino[(i + (3 * i)) + zero] != '#')
	{
		i++;
		if (i == 3)
		{
			zero++;
			i = 0;
		}
	}
	return (zero);
}
//    0123
//	0.0000	y_0 =  1 x_0 = 2
//	1.00##	array[4][2] =  ( 6 % 4 - x_0 ) = ( 2 - 2) = 0 , (7 % 3 - x_0) = (3 - 2) = 1       {0 , 0}
//  2.00##					( 10 % 4 - x_0 ) = (2 - 2) = 0 , ( 11 % 4 - x_0 ) = (3 - 2) = 1 
//  3.0000
//  
//

void	add_to_row(t_row **row, char *tetrimino, int x, int y)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 16)
	{
		if (i > 3 && i % 4 == 0)
			j++;
		if (tetrimino[i] == '#')
		{
			(*row)->tetr[k][0] = i % 4 - x;
			(*row)->tetr[k++][1] = j - y;
		}
		i++;
	}
}

void	print_4_2_array(t_row *row)
{
	printf("name: %s\n", row->name);
	printf("(%d,", row->tetr[0][0]);
	printf("%d)\n", row->tetr[0][1]);
	printf("(%d,", row->tetr[1][0]);
	printf("%d)\n", row->tetr[1][1]);
	printf("(%d,", row->tetr[2][0]);
	printf("%d)\n", row->tetr[2][1]);
	printf("(%d,", row->tetr[3][0]);
	printf("%d)\n", row->tetr[3][1]);
}

void	add_to_list(t_row *row, t_row **root)
{
	(*root)->down = row;
	row->down = *root;
}

/*
 * 	This functions called n times, n = amount of tetrimino
 */
void	add_to_struct(char *tetrimino, t_row **root)
{
	int y_0;
	int x_0;
	t_row *row;
//	static t_row *root;
	
	row = (t_row*)malloc(sizeof(t_row));	
	y_0 = count_zeros_rows(tetrimino);
	x_0 = count_zeros_columns(tetrimino);
	add_to_row(&row, tetrimino, x_0, y_0);
	print_4_2_array(row);	
	add_to_list(row, root);
}

void	error()
{
	//free allocated memory
	ft_putstr("error\n");
	return;
}

int		chk_vld_add_stru(char *tetrimino, t_row **root)
{
	if (chk_out_of_bounds(tetrimino) == 0)
		return (0);
	if (chk_edges_connected(tetrimino, 4) < 6)
		return (0);
	add_to_struct(tetrimino, root);
	return (1);
}


void	init_root(t_row **root)
{
	*root = (t_row*)malloc(sizeof(t_row));
	(*root)->down = *root;
	(*root)->up = *root;
}

void	read_to_array(int fd)
{
	char	*line;
	char	*tetrimino;
	int		max;
	int		i;
	int 	ret;
	t_row	*root;

	init_root(&root);
	i = -1;
	max = 0;
	tetrimino = ft_strnew(16);
	ret = get_next_line(fd, &line);
	while (++i < 4 && ret >= 1)
	{
		tetrimino = ft_strjoin(tetrimino, line);
		if (i == 3)
		{
			i = -1;
			if(++max > MAX_TETRIMINOS)
				error();
			if (chk_vld_add_stru(tetrimino, &root) == 0)
				error();
		//	printf("tetrimino - %s\n", tetrimino);
			ft_strclr(tetrimino);
		}
		ret = get_next_line(fd, &line);
	}
	//	solve();
}
