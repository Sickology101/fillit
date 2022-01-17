/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtoarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 04:46:52 by severi            #+#    #+#             */
/*   Updated: 2022/01/17 13:05:32 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_strcountchr(char *str, char c)
{
	int count;

	while (*str == c || *str != '\0')
	{
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
	if (i % nxn_size > 1)
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
// ####
// ....
// ....
// ....
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
		if (tetr[++i] == '#')
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

// 1000100010001000
// 0   4   8   12131415
//
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

void	add_to_struct(char *tetrimino)
{
	int y_0;
	int x_0;
	//t_row row;
	
	y_0 = count_zeros_rows(tetrimino);
	x_0 = count_zeros_columns(tetrimino);
	
	x_0 = y_0 + x_0;
	// TODO: row->tetr ;
	
}

void	error()
{
	//free allocated memory
	ft_putstr("error\n");
	return;
}

int		chk_vld_add_stru(char *tetrimino)
{
	if (chk_out_of_bounds(tetrimino) == 0)
		return (0);
	if (chk_edges_connected(tetrimino, 4) < 6)
		return (0);
	add_to_struct(tetrimino);
	return (1);
}




void	read_to_array(int fd)
{
	char	*line;
	char	*tetrimino;
	int	max;
	int	i;
	int ret;

	i = -1;
	max = MAX_TETRIMINOS;
	tetrimino = ft_strnew(16);
	ret = get_next_line(fd, &line);
	while (++i < 4 && ret >= 1)
	{
		tetrimino = ft_strjoin(tetrimino, line);
		if (i == 3)
		{
			i = -1;
			if(++max > 26)
				error();
			if (chk_vld_add_stru(tetrimino) == 0)
				error();
			ft_strclr(tetrimino);
		}
		ret = get_next_line(fd, &line);
	}
	solve();
}
