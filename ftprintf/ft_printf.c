/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:37:19 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/27 15:06:12 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	excesdeprint(const char **format, va_list ptr, int *charcount)
{
	char				*printstring;
	char				printchar;
	int					num;

	if (**format == 's')
	{
		printstring = va_arg(ptr, char *);
		if (printstring == NULL)
			printstring = "(null)";
		ft_putstr_fd(printstring, 1);
		*charcount += ft_strlen(printstring);
	}
	if (**format == 'c')
	{
		printchar = (char)va_arg(ptr, int);
		ft_putchar(printchar);
		*charcount += 1;
	}
	if (**format == 'd' || **format == 'i')
	{
		num = va_arg(ptr, int);
		*charcount += ft_putnbr(num);
	}
	*format += 1;
	return (*charcount);
}

static int	printdecandhexdec(const char **format, va_list ptr, int *charcount)
{
	unsigned int		numb;
	unsigned long int	number;

	if (**format == 'p')
	{
		number = va_arg(ptr, unsigned long int);
		*charcount += pointer(number);
	}
	else
	{
		numb = va_arg(ptr, unsigned int);
		if (**format == 'x' || **format == 'X')
			*charcount += hexadecimal(numb, **format);
		else
			*charcount += ft_putnbrunsigned(numb);
	}
	*format += 1;
	return (*charcount);
}

static int	printformat(const char **format, int *charcount)
{
	ft_putchar(**format);
	*charcount += 1;
	*format += 1;
	return (*charcount);
}

int	ft_printf(const char *format, ...)
{
	int				charcount;
	va_list			ptr;

	charcount = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || \
					*format == 'i' || *format == 'd')
				charcount = excesdeprint(&format, ptr, &charcount);
			else if (*format == '%')
				charcount = printformat(&format, &charcount);
			else if (*format == 'x' || *format == 'X' || \
					*format == 'u' || *format == 'p')
				charcount = printdecandhexdec(&format, ptr, &charcount);
		}
		else
			charcount = printformat(&format, &charcount);
	}
	va_end(ptr);
	return (charcount);
}
