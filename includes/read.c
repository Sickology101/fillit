/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:32:32 by marius            #+#    #+#             */
/*   Updated: 2022/01/13 11:11:36 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* 
We use this to read the file and save the tetriminos inside a liked list of 2d arrays
*/

int	get_tetrimino(int fd, char **savefile, int *error)
{
	int		index;
	int		ret;
	char	*line;
	char	*tetrimino;

	ret = 1;
	index = 0;
	tetrimino = (char *)malloc(sizeof(char) * 16);
	while (ret > 0 && index < 4)
	{
		ret = get_next_line(fd, &line);
		tetrimino = ft_strjoin(tetrimino, line);
		index++;
	}
	if (*error != -1)
		*error = check_valid(tetrimino);
	else
		return (-1);
	if (*error != -1)
		*savefile = ft_strjoin(*savefile, tetrimino);
	else
		return (-1);
	return (ret);
}

char	*read_file(int fd, int *error)
{
	int		ret;
	char	*savefile;

	ret = 1;
	savefile = (char *)malloc(sizeof(char) * MAX_SIZE);
	while (ret == 1)
	{
		ret = get_tetrimino(fd, &savefile, error);
	}
	if (*error != -1)
		return (savefile);
	else
		{
			free(savefile);
			printf("%d",*error);
			return (NULL);
		}
}
