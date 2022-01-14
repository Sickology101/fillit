/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:25 by marius            #+#    #+#             */
/*   Updated: 2022/01/14 16:07:58 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;
	//t_list	link;

	if (argc > 1)
	{
		ft_putstr("./fillit filename.txt should be used to run fillit");
		return(-1);
	}
	fd = open(argv[1], O_RDONLY);
	//read_file(fd, link);
	close(fd);
	return (0);
}
