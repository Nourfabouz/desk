
# include <stdlib.h>
#include <stdio.h>
# include "libft.h"
	
void *ft_calloc(size_t count, size_t size){
	void *p;
	void *ptr;
	
	p = malloc(count * size);
	if (p == NULL)
		return NULL;
	ptr = memset(p, 0, count * size);
	return ptr;
}

int main()
{
	int *p;
	int i;

	p = (int *) ft_calloc(5, 4);

	i = 0;
	while (i < 5)
	{
		printf("%d", p[i]);
		i++;
	}
}
