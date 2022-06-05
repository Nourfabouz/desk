#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *ptr;
	int len;
	int pos;
	int pos1;
	int i;

	i = 0;
	if  (!s1 || !set)
		return  "\0";
	while (ft_strchr(set, s1[i]))
		i++;
	pos = i;
	len = (int) ft_strlen(s1);
	i = len - 1;
	pos1 = i;
	while (ft_strchr(set, s1[i]))
		i--;
	pos1 = i;
	len = pos1 - pos + 1;
	ptr = ft_substr(s1, pos, len);
	return ptr;
}

int main()
{
	char s[] = "abcfaizaabouabc";
	char *p;

	p = ft_strtrim(s, "abc");
	printf("%s", p);
}
