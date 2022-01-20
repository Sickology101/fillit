/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfromfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:22:10 by severi            #+#    #+#             */
/*   Updated: 2022/01/20 03:35:52 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_4_2_array(t_row *row)
{
	printf("name: %s\n", row->name);
	printf("(%d,", row->tetr[0][0]);
	printf("%d)\n", row->tetr[0][1]);
	printf("(%d,", row->tetr[1][0]);
	printf("%d)\n", row->tetr[1][1]);
	printf("(%d,", row->tetr[2][0]);
	printf("%d)\n", row->tetr[2][1]);
	printf("(%d,", row->tetr[3][0]);
	printf("%d)\n", row->tetr[3][1]);
}

/**
 * TODO: ADD freeing of allocated memory, UPDATE:
 * might not be necessary with exit() but is it allowed?
 * See conversion in Discord.
 */
void	error(int res)
{
	if (res == -1)
		ft_putstr("read error ");
	if (res == 1)
		ft_putstr("tetrimino not 16 chars, 12 empty, 4 valid! ");
	if (res == 2)
		ft_putstr("tetrimino connections under minium of 6. ");
	if (res == 3)
		ft_putstr("over 26 tetriminoes! ");
	ft_putstr("error\n");
	exit(res);
	return ;
}

void	init_root(t_row **root)
{
	*root = (t_row *) malloc (sizeof(t_row));
	(*root)->down = *root;
	(*root)->up = *root;
}

int	get_lines(int fd, t_row **root, char **tetrimino)
{
	char	*line;
	int		max;
	int		i;
	int		ret;

	i = -1;
	max = 0;
	ret = get_next_line(fd, &line);
	if (ret < 1)
		return (-1);
	while (++i < 4 && ret >= 1)
	{
		*tetrimino = ft_strjoin(*tetrimino, line);
		if (i == 3)
		{
			i = -1;
			if (++max > MAX_TETRIMINOS || \
				chk_vld_add_stru(*tetrimino, root) != 0)
				return (3);
			printf("tetrimino - %s\n", *tetrimino);
			ft_strclr(*tetrimino);
			ret = get_next_line(fd, &line);
		}
		ret = get_next_line(fd, &line);
	}
	return (0);
}

void	read_to_array(int fd)
{
	t_row	*root;
	char	*tetrimino;
	int		result;

	tetrimino = ft_strnew(16);
	init_root(&root);
	result = get_lines(fd, &root, &tetrimino);
	ft_strdel(&tetrimino);
	if (result == 0)
		solve();
	else
		error(result);
}
