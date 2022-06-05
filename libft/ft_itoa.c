/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:51:25 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/13 10:14:04 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chiffrecal(int n)
{
	int	div;
	int	count;

	div = 0;
	count = 0;
	while (n < -9 || n > 9)
	{
		div = n / 10;
		count++;
		n = div;
	}
	if (n < 0)
		count++;
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		count;
	int		i;

	sign = 1;
	if (n < 0)
		sign = -1;
	count = chiffrecal(n);
	ptr = (char *) malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = count - 1;
	while (i >= 0)
	{
		ptr[i] = ((n % 10) * sign) + 48;
		n = n / 10;
		i--;
	}
	ptr[i] = n + 48;
	if (sign == -1)
		ptr[0] = '-';
	ptr[count] = '\0';
	return (ptr);
}
