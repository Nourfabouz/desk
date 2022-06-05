/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:32:36 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/24 20:56:05 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer(unsigned long int n)
{
	char		*base16;
	char		nout;
	static int	countp;

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
