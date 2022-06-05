# include <stdlib.h>
# include "libft.h"
#include <stdio.h>

char *ft_strdup(const char *s1)
{
	int len;
	char *p;
	int i;

	len = 0;
	while (s1[len])
		len++;

	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return NULL;
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
int main()
{
	char s[] = "faiza";
	char *p = ft_strdup(s);
	printf("%s", p);
}
