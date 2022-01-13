/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:31:25 by marius            #+#    #+#             */
/*   Updated: 2022/01/13 11:06:00 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

/*
Here is where the magic happens
*/

int	main(int argc, char **argv)
{
	int	fd;
	int	error;

	error = 0;
	if (argc != 2)
	{
		ft_putstr("./fillit filename.txt should be used to run fillit");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%s", read_file(fd, &error));
}
