#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char *str, int fd)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbrunsigned(unsigned int n)
{
	static int countun;
	countun = 0;
	if (n > 9)
	{
		countun++;
		ft_putnbrunsigned( n / 10);
	}
	countun++;
	ft_putchar((n % 10) + 48);
	return (countun);
}

int	ft_putnbr(int n)
{
	int sign;
	static int countin;
	
	countin = 0;
	sign = 1;
	if (n < -9 || n > 9)
	{
		countin++;
		ft_putnbr(n / 10);
	}
	countin++;
	if (n < 0 && n >= -9)
	{
		ft_putchar('-');
		countin++;
	}
	if (n < 0)
		sign = -1;
	ft_putchar((n % 10) * sign + 48);
	return (countin);
	
}

int	pointer(unsigned long int n)
{
	char *base16;
	char nout;
	static int countp;

	if (!n)
		return 0;
	base16 = "0123456789abcdef";
	countp = 0;
	if (n >= 16)
		pointer(n / 16);
	if (!countp)
	{
		write(1, "0x", 2);
		countp += 2;
	}
	nout = base16[n % 16];
	ft_putchar(nout);
	countp++;
	return (countp);
}
int	hexadecimal(unsigned int n, char c)
{
	char *base16;
	char nout;
	static int counthex;

	base16 = "0123456789abcdef";
	counthex = 0;
	if (n >= 16)
		hexadecimal(n / 16, c);
	if ( c == 'x')
		nout = base16[n % 16];
	else
	{
		if ((base16[n % 16] >= 'a' && base16[n % 16] <= 'z'))
			nout = base16[n % 16] - 32;
		else
			nout = base16[n % 16];
	}
	ft_putchar(nout);
	counthex++;
	return (counthex);
}

int excesdeprint(const char **format, va_list ptr, int *charcount)
{
	char *printstring;
    char printchar;
    int num;
    unsigned long int number;

	if (**format == 's')
	{
	   	printstring = va_arg(ptr, char *);
		ft_putstr_fd(printstring, 1);
		*charcount += strlen(printstring);
		*format += 1;
	}
	if (**format == 'c')
	{
		printchar = (char)va_arg(ptr, int);
		ft_putchar(printchar);
		*charcount += 1;
		*format += 1;
	}
	if (**format == 'd' || **format == 'i')
	{
		num = va_arg(ptr, int);
		*charcount += ft_putnbr(num);
		*format += 1;
	}
	if (**format == 'p')
	{
		number = va_arg(ptr, unsigned long int);
		*charcount += pointer(number);
		*format += 1;
	}
	return (*charcount);
}
int	ft_printf(const char *format, ...)
{
	int charcount;
	va_list ptr;
	/*char *printstring;
	char printchar;
	int num;
	unsigned long int number;*/
	unsigned int numb;
	
	charcount = 0;
	va_start(ptr, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			/*if (*format == 's')
			{
				printstring = va_arg(ptr, char *);
				ft_putstr_fd(printstring, 1);
				charcount += strlen(printstring);
				format++;
			}
			if (*format == 'c')
			{
				printchar = (char)va_arg(ptr, int);
				ft_putchar(printchar);
				charcount++;
				format++;
			}
			if (*format == 'd' || *format == 'i')
			{
				num = va_arg(ptr, int);
				charcount += ft_putnbr(num);
				format++;
			}
			if (*format == 'p')
			{
				number = va_arg(ptr, unsigned long int);
				charcount += pointer(number);
				format++;
			}*/
			charcount = excesdeprint(&format, ptr, &charcount);
			if (*format == '%')
			{
				write(1, format, 1);
				charcount++;
			}
			if (*format == 'x' || *format == 'X' || *format == 'u')
			{
				numb = va_arg(ptr, unsigned int);
				if (*format == 'x' || *format == 'X')
					charcount += hexadecimal(numb, *format);
				else
					charcount += ft_putnbrunsigned(numb);
				format++;
			}
		}

		else
		{
			ft_putchar(*format);
			charcount++;
			format++;
		}	
	}
	va_end(ptr);
	return (charcount);
}

int main()
{
	int car = 0;
	int carp = 0;
	char str[] = "Faiza";
	int num = -1524;
	int *p;
	p = &car;
	unsigned int numb = 431234567;
	car = ft_printf("Abouzaher %% %s %c %d %i %u %p %x %X", str, '\0', num, num, numb, p, numb, numb);
	printf("\n im printf:\n");
	carp = printf("Abouzaher %% %s %c %d %i %u %p %x %X", str, '\0', num, num, numb, p, numb, numb);
	printf("\n im for new printf %d\n", car);
	printf("im for real printf %d", carp);
} 
