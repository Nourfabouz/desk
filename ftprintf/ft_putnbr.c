/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:19:22 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/24 14:28:03 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			sign;
	static int	countin;

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
