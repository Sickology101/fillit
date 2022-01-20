/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtoarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 04:46:52 by severi            #+#    #+#             */
/*   Updated: 2022/01/20 03:33:37 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	count_zeros_rows(char *tetrimino)
{
	int	zero;
	int	i;

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

static int	count_zeros_columns(char *tetrimino)
{
	int	zero;
	int	i;

	zero = 0;
	i = 0;
	while (tetrimino[(i + (3 * i)) + zero] != '#')
	{
		i++;
		if (i == 4)
		{
			zero++;
			i = 0;
		}
	}
	return (zero);
}

void	add_to_row(t_row **row, char *tetrimino, int x, int y)
{
	int	i;
	int	j;
	int	k;

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

/*
 * 	This functions called n times, n = amount of tetrimino
 */
void	add_to_struct(char *tetrimino, t_row **root)
{
	int		y_0;
	int		x_0;
	t_row	*row;
//?	static t_row *root;
	row = (t_row *) malloc (sizeof(t_row));
	y_0 = count_zeros_rows(tetrimino);
	x_0 = count_zeros_columns(tetrimino);
	add_to_row(&row, tetrimino, x_0, y_0);
	print_4_2_array(row);
	add_to_list(row, root);
}

int	chk_vld_add_stru(char *tetrimino, t_row **root)
{
	if (chk_out_of_bounds(tetrimino) == 0)
		error(1);
	if (chk_edges_connected(tetrimino, 4) < 6)
		error(2);
	add_to_struct(tetrimino, root);
	return (0);
}
