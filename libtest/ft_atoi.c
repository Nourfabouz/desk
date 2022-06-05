#include "libft.h"
#include <stdio.h>


int ft_atoi(const char *str){

	int i;
	int n;
	int negtv;
	int sum;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;

	negtv = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negtv = -1;
		i++;
	}

	sum = 0;
	n = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		n = (str[i] - 48);
		sum = ((sum * 10) + n * negtv);
		i++;
	}
	return ((int)sum);
}

int main()
{
	char s[] = "  +523658  ";
	int n;

	n = ft_atoi(s);
	printf("%d", n);
}
	
