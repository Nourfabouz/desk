# include"libft.h"
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long dstlen;
	unsigned long srclen;
	unsigned long count;

	dstlen = 0;
	while (dst[dstlen] != '\0')
	{
		dstlen++;
	}

	srclen = 0;
	while (src[srclen] != '\0')
	{
		srclen++;
	}

	if (dstsize < dstlen + 1)
		return (dstsize + srclen);

	count = 0;
	while ((count + dstlen + 1 < dstsize) && src[count])
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';

	return (dstlen + srclen);
}

int main()
{
	char s[] = "faiza";
	char s1[] = "abouz";
	unsigned long n = ft_strlcat(s, s1, 8);
	printf("%s\n", s);
	printf("%lu", n);
}
