/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:13:35 by severi            #+#    #+#             */
/*   Updated: 2022/01/20 17:23:33 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_in_col()
{

}
	
void	insert_in_row()
{
	
}

void	add_node(t_row)
{
	
}

void	link_matrix(t_row root, t_col **col, int size)
{
	t_row	*row;
	int		i;
	int		col_id;
	
	row = root->down;
	while (row != root)
	{
		i = 0;
		while (i < 4)
		{
			col_id = row->tetr[i][1] * size + row->tetr[i][0];
			add_node(row, col[col_id]);
			i++;
		}
		row = row->down;
	}
	
}




