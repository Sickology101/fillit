/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfromfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:22:10 by severi            #+#    #+#             */
/*   Updated: 2022/01/21 18:58:57 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int res)
{
	ft_putstr("error\n");
	exit(res);
	return ;
}

void	init_root(t_row **root)
{
	*root = (t_row *) malloc (sizeof(t_row));
	(*root)->down = NULL;
	(*root)->up = *root;
	(*root)->name = '\0';
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
		solve(root);
	else
		error(result);
}
