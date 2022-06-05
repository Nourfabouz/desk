# include"libft.h"
#include <stdio.h>

char *ft_strchr(const char *s, int c){
	int i;

	i = 0;

	while ( s[i]!='\0'){
		if (s[i] == (char)c)
			return (char*)s + i;
		i++;
	}

	if (c == '\0')
		return (char*)s+i;
	return NULL;
}

int main()
{
	char *p;
	char s[] = "nafahofurajf";
	p = ft_strchr(s, 'f');
	printf("%s", p);
}
