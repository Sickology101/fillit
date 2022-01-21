/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:25 by marius            #+#    #+#             */
/*   Updated: 2022/01/21 18:20:51 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr("./fillit filename.txt should be used to run fillit\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	
	/*int i = argc;
	char *o = argv[1];
	ft_strdel(&o);
	i = i + 2;
	fd = open("eval_tests/two_tetrimino", O_RDONLY);*/
	if (fd == -1)
		error(-1);
	read_to_array(fd);
	close(fd);
	return (0);
}
