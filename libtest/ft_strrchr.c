# include "libft.h"
#include <stdio.h>

char* ft_strrchr( const char *s, int c)
{
	int i;
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	char cr = (char) c;

	if ( c == '\0')
		return ((char*)s+len);

	i = len - 1;
	while (i >= 0)
	{
		if (s[i] == cr)
			return ((char*)s+i);
		i--;
	}

return NULL;
}	
	
int main()
{
    char *p;
    char s[] = "nafahfouraj";
    p = ft_strrchr(s, 'f');
    printf("%s", p);
}


