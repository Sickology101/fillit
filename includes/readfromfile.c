/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfromfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:22:10 by severi            #+#    #+#             */
/*   Updated: 2022/01/21 23:36:37 by severi           ###   ########.fr       */
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

/*
 * TODO: This functions needs rewriting from strach. It does not pass
 * norm, it has memory leak on line 62 which I can't fix and does not work with  
 * 	'eval_tests/bad_tetrimino_2nd_empty' for example.
 */
int	get_lines(int fd, t_row **root, char **tetrimino, char **line)
{
	int		max;
	int		i;
	int		ret;
	char	*temp;

	i = -1;
	max = 0;
	ret = get_next_line(fd, line);
	if (ret < 1)
		return (-1);
	while (++i < 4 && ret >= 1)
	{
		temp = ft_strjoin(*tetrimino, *line);
		ft_strdel(tetrimino);
		*tetrimino = temp;
		if (i == 3)
		{
			i = -1;
			if (++max > MAX_TETRIMINOS || \
				chk_vld_add_stru(*tetrimino, root) != 0)
				return (3);
			ft_strclr(*tetrimino);
			ret = get_next_line(fd, line);
		}
		ft_strdel(line);
		ret = get_next_line(fd, line);
	}
	ft_strdel(line);
	return (0);
}

void	read_to_array(int fd)
{
	t_row	*root;
	char	*tetrimino;
	char	*line;
	int		result;

	tetrimino = ft_strnew(16);
	init_root(&root);
	result = get_lines(fd, &root, &tetrimino, &line);
	ft_strdel(&tetrimino);
	ft_strdel(&line);
	if (result == 0)
		solve(root);
	else
		error(result);
}
