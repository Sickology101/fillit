/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:25 by marius            #+#    #+#             */
/*   Updated: 2022/01/17 19:08:29 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;
	//t_list	link;

	if (argc != 2)
	{
		ft_putstr("./fillit filename.txt should be used to run fillit");
		return(-1);
	}
	fd = open(argv[1], O_RDONLY);
	read_to_array(fd);
	close(fd);
	return (0);
}
