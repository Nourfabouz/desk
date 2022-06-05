# include"libft.h"
#include <stdio.h>

 size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long i;
	unsigned long srcsize;

	if (dstsize != 0)
	{
		i = 0;
		while ( (i + 1 < dstsize) && (src[i] != '\0')){
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}

	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	return srcsize; 
}

int main()
{
	char s[] = "faijkijji";
	char s1[] = "abouz";
	unsigned long n;
	n = strlcpy(s, s1, 4);
	printf("%s\n", s);
	printf("%lu", n);
}

