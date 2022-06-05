#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fpointer;
	char *oneline;

	fpointer = open("text.txt", O_RDONLY);
	while ((oneline = get_next_line(fpointer)) != NULL)
	{
		printf("%s", oneline);
	}
	return (0);
}
