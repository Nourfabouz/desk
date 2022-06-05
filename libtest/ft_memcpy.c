# include"libft.h"
#include <stdio.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst1;
	unsigned char *src1;
	unsigned long i;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	
	if (dst1 == NULL && src1 == NULL)
		return NULL;
	i = 0;
	while (i < n )
	 {
		 dst1[i]=src1[i];
		 i++;
	 }
	return dst1;
}

int main()
{
	char s[] = "nabou";
	char s1[] = "faizall";
	char *p;

	p = ft_memcpy(s, s1, 3);
	printf("%s", p);
}	
