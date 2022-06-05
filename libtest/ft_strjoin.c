#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2){

	char *ptr;
	char *dst;
	size_t i;
	size_t len;
	size_t lentotal;

	lentotal = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) malloc((lentotal + 1) * sizeof(char));
	if (ptr == NULL)
		return NULL;

	dst = (char *)s1;
	i = 0;
	while (dst[i]){
		ptr[i] = dst[i];
		i++;
	}
	ptr[i] = '\0';
	len = ft_strlcat(ptr, s2, lentotal + 1);
	return ptr;
}
