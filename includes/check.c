/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:03:03 by marius            #+#    #+#             */
/*   Updated: 2022/01/13 11:00:46 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	if_connected(char *tetrimino, int index)
{
	if (index - 1 >= 0)
		if (tetrimino[index] == '#')
			return (1);
	if (index + 1 <= 4)
		if (tetrimino[index] == '#')
			return (1);
	if (index - 4 >= 0)
		if (tetrimino[index] == '#')
			return (1);
	if (index + 4 <= 16)
		if (tetrimino[index] == '#')
			return (1);
	return (0); 
}

int	check_valid(char *tetrimino)
{
	int	index;
	int error;

	error = 1;
	index = 0;
	while (tetrimino[index] != '\0' && error == 1)
	{
		if (tetrimino[index] == '#')
			error = if_connected(tetrimino, index);
		index++;
	}
	if (index > 17)
		return (0);
	return (1);
}