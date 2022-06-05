# include "libft.h"
#include <stdio.h>

void* ft_memset(void *str, int c, size_t  n){
	unsigned char *s;
	unsigned long i;

	s = (unsigned char*) str;
	i = 0;
	while (i < n){
		s[i] = (unsigned char)c;
		i++;
	}
	return str;
}

int main()
{
	int i;
	int s[] = {5, 2, 3, 4, 8};
	ft_memset(s, 0, 20);
	i = 0;
	while ( i < 5)
	{
		printf("%d", s[i]);
		i++;
	}
}
