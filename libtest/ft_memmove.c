# include "libft.h"
#include <stdio.h>

void *ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char *dst1;
	unsigned char *src1;
	size_t			i;


	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;

	if (dst1 < src1)
	{
		i = 0;
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else if (dst1 > src1)
	{
		i = 0;
		while ( i < len)
		{
			dst1[len - 1 - i] = src1[len - 1 - i];
			i++;
		}
	}
	return dst;
}

int main()
{
	char s[] = "faiabcza";
	ft_memmove(s + 3, s, 3);
	printf("%s", s);
}

