/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:32:32 by marius            #+#    #+#             */
/*   Updated: 2022/01/12 15:09:11 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
We use this to read the file and save the tetriminos inside a liked list of 2d arrays
*/

int	get_tetrimino(int fd, char **tetrimino)
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
	return (ret);
}

int	read_file(int fd, t_list link)
{
	int		fd;
	int		ret;
	

	ret = 1;
	index = 0;
	ft_new_d_link(link);
	while (ret == 1)
	{
		ret = get_tetrimino(fd, link->content);
		check_valid(link->cotent);
		link = link->next;
	}
}
