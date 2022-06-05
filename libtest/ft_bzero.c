# include"libft.h"
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	unsigned char *str;
	unsigned long i;
		
	str = (unsigned char*) s;
	i=0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int main()
{
	char s[] = "faiza";
	ft_bzero(s, 3);
	printf("%s",  s);
}
