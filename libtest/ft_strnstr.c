# include"libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    unsigned long lenNeedle;
    unsigned long i;
    int strcmp;
    char *stack;

    lenNeedle = ft_strlen(needle);
    stack = (char *) haystack;

    i = 0;
    
    if (needle[0] == '\0')
	    return (stack);

    while (i < len && stack[i])
    {
	   	if (stack[i] == needle[0] && len - i >= lenNeedle)
	   	{
			strcmp = ft_strncmp((stack+i), needle, lenNeedle);
			if (strcmp == 0)
				return (stack+i);
	   	}
		i++;
	}
	return NULL;
}
