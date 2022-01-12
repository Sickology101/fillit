/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_d_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:53:21 by marius            #+#    #+#             */
/*   Updated: 2022/01/12 15:16:53 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_list	*ft_new_d_link(void	*previous)
{
	d_list	*list;

	list = (d_list *)malloc(sizeof(d_list));
	if (!list)
		return (0);
	list->content = malloc(sizeof(char *) * 4);;
	list->previous = previous;
	list->next = NULL;
	return (list);
}