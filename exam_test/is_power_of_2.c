#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if ((n % 2) == 0)
		return(1);
	else
		return(0);
}

int main()
{
	printf("%d", is_power_of_2(15));
}
