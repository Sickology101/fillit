/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:32:32 by marius            #+#    #+#             */
/*   Updated: 2022/01/11 17:41:07 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
We use this to read the file and save the tetriminos inside a liked list of 2d arrays
*/

void	get_tetrimino(int fd, char **tetrimino)
{
	int	index;
	int	ret;

	ret = 1;
	index = 0;
	while (ret > 0 && index < 4)
	{
		ret = get_next_line(fd, &tetrimino[index]);
		index++;
	}
}

/*int	if_connected(char **tetrimino, int i, int j, int c)
{
	if (tetrimino[i][j - 1] == '#' || tetrimino[i][j - 1] == c)
		return (1);
	if (tetrimino[i][j + 1] == '#' || tetrimino[i][j + 1] == c)
		return (1);
	if (tetrimino[i - 1][j] == '#' || tetrimino[i - 1][j] == c)
		return (1);
	if (tetrimino[i + 1][j] == '#' || tetrimino[i + 1][j] == c)
		return (1);
	return (0);
}

int	check_valid(char **tetrimino, int c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (tetrimino[i] != NULL && i < 5)
	{
		j = 0;
		while (tetrimino[i][j] != '\0' && j < 5)
		{
			if (tetrimino[i][j] != '.')
			{
				if (tetrimino[i][j] == '#' && if_connected(tetrimino, i, j))
					{
						tetrimino[i][j] = c;
						index++;
					}
				else
					return (0);
			}
			j++;
		}
		if (j != 3 || index > 4)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}
*/
int	read_file(int fd, t_list link)
{
	int		fd;
	int		ret;
	

	ret = 1;
	index = 0;
	get_tetrimino(fd, link->content);
	check_valid(link->cotent);
	link = link->next;
	if (ret == 1)
		ret = read_file(fd, link);
}
