/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:25 by marius            #+#    #+#             */
/*   Updated: 2022/01/11 17:46:08 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
Here is where the magic happens
*/

int	main(int argc, char **argv)
{
	int	fd;
	t_list	link;

	if (argc > 1)
	{
		ft_putstr("./fillit filename.txt should be used to run fillit");
		return(-1);
	}
	fd = open(argv[1], O_RDONLY);
	read_file(argv[1], link);
}
