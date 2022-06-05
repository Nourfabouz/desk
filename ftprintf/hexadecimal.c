/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:13:45 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/25 14:22:58 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hexadecimal(unsigned int n, char c)
{
	char		*base16;
	char		nout;
	static int	counthex;

	base16 = "0123456789abcdef";
	counthex = 0;
	if (n >= 16)
		hexadecimal(n / 16, c);
	if (c == 'x')
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
