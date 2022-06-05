#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len){
	char *ptr;
	unsigned long i;
	unsigned long j;
	unsigned long lens;

	if (s == NULL)
        return (NULL);
    lens = ft_strlen(s);
    if (start >= lens)
        len = 0;
    if (len > (lens - start))
        len = lens - start;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if ( ptr == NULL)
		return NULL;
	i = start;
	j = 0;
	while (j < len && s[i] != '\0'){
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int main()
{
	char s[] = "naflufifatiaszah";
	char *p;
	p = ft_substr(s, 3, 10);
	printf("%s", p);
}
