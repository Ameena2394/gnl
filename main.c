#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("tests/test.txt", O_RDONLY);
	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}