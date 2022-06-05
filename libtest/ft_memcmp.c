# include "libft.h"
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long i;
	unsigned char *str1 = (unsigned char *) s1;
	unsigned char *str2 = (unsigned char*) s2;

	if (n == 0)
		return 0;

	i = 0;
	while (i  < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i - 1] - str2[i - 1]);
}

int main()
{
	char s[] = "faouzi";
	char s1[] = "faouzho";
	int n;

	n = ft_memcmp(s, s1, 7);
	printf("%d", n);
}
