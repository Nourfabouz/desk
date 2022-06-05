#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main(int c, char **v)
{
	char *line;

	int fd = open(v[c - 1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while (1)
	{}
}
