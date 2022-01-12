/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_d_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:53:21 by marius            #+#    #+#             */
/*   Updated: 2022/01/12 18:07:37 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_node	*ft_new_node(char *name, int size)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->name = name;
	node->size = size;
	node->up = NULL;
	node->down = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void	ft_del_node(t_node **node)
{
	node->right	= node;
	node->left = node;
	node->up = node;
	node->down = node;
}

void	ft_add_node(t_node *up, t_node *down, t_node *left, t_node *right)
{
	

}
