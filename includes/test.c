#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	//int	fd = open("basic.txt", O_RDONLY);
	int	fd = open(argv[1], O_RDONLY);
	//int	fd = 42;
	int test;
	test = argc;
	int index;

	char	*line[4];
	int i = 1;
	
	index = 0;
	while (i > 0 && index < 4)
	{
		i = get_next_line(fd, &line[index]);
		index++;
	}
	index = 0;
	while (index < 4)
	{
		printf("%s\n",line[index]);
		index++;
	}
	return (0);
}