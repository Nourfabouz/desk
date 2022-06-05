# include "libft.h"
#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str = (unsigned char *) s;
	unsigned char crt = (unsigned char) c;
	unsigned long i;

	i = 0;
	while ( i < n)
	{
		if ( str[i] == crt)
			return ((void *)s + i);
		i++;
	}
	return NULL;
}

int main()
{
	char *p;
	char s[] = "mmfahouf";
	p = ft_memchr(s, 'f' , 3);
	printf("%s", p);
}

