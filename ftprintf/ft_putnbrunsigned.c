/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:28:37 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/24 14:30:26 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrunsigned(unsigned int n)
{
	static int	countun;

	countun = 0;
	if (n > 9)
	{
		countun++;
		ft_putnbrunsigned(n / 10);
	}
	countun++;
	ft_putchar((n % 10) + 48);
	return (countun);
}
