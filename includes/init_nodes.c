/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:19:05 by severi            #+#    #+#             */
/*   Updated: 2022/01/13 01:33:39 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/** 
 * Cover is to remove header from the list
 * and then the rest of the nodes in the rows matching
 * that column.
 */

void	cover(t_node *node)
{
	t_node	*i;
}

/**
 * Reverse the cover
 *
 *
 */

void	uncover(t_node *node)
{
	t_node	*i;
}

void	create_header_row(t_header_node *base, t_header_node *header, size_t n)
{
	t_node *node;

	node = (t_node *) base;
	node->left = (t_node *) (header + n - 1);
	node->right = (t_node *) header;
	node->up = NULL;
	node->down = NULL;
	node->header = NULL;
	base->size = 1;

	node = 
}

void	create_row(t_node *nodes, char *name, size_t n)
{
	size_t	i;
	t_node	node;

	i = 0;
	node = nodes
	node->left = node + n - 1;
	node->right = node + 1;
	while(i < n - 1)
	{
		node->left = node - 1;
		node->right = node + 1;
		node++;		
		i++;
	}
	node->left = node - 1;
	node->right = nodes;
}

/**
 * Insert node n into bottom of column header and increase size
 */

void	add_row(t_node *nodes, t_header_node **header, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		node->header = header;
		node->up = ((t_node *) header)->up;
		node->down = (t_node *) header;
		node->up->down = node;
		node->down->up = node;
		header->size++;
		i++
	}
}
