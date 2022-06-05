#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int main()
{
	char s[] = "faizab";
	char s1[] = "";
	printf("%d", ft_strcmp(s, s1));
}
