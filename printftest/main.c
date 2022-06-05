#include "../ftprintf/ft_printf.h"
#include <stdio.h>

int main()
{
	int car = 0;
	int carp = 0;
	// char str[] = "Faiza";
	// char s[] = "Hussein";
	// int num = -1524;
	// int *p;
	// p = &car;
	//p = 0;
	// unsigned int numb = 431234567;
	car = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf(NULL);
	carp = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nim for new printf %d\n", car);
	printf("im for real printf %d\n", carp);
}
