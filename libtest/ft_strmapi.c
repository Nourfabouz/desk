#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char funplus(unsigned int i, char c)
{
	char cr;
	cr = c + i;
	return (cr);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)){

	int len;
	char *ptr;
	int i;

	if (s == NULL)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	ptr = (char*) malloc ((len + 1) * sizeof(char));
	if (ptr == NULL)
		return NULL;
	i = 0;
	while (s[i]){
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return ptr;
}

int main(){
	char s[] = "01234";
	char *ptr;

	ptr = ft_strmapi(s, funplus);
	printf("%s", ptr);
}
