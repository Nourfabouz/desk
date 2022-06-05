/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:06:52 by fabou-za          #+#    #+#             */
/*   Updated: 2021/11/27 12:37:17 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n >= -9)
		ft_putchar_fd('-', fd);
	if (n < 0)
		sign = -1;
	ft_putchar_fd((n % 10) * sign + 48, fd);
}
