/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:52:31 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/09 17:55:59 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				negtv;
	int				sum;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	negtv = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negtv = -1;
		i++;
	}
	sum = 0;
	n = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		n = (str[i] - 48);
		sum = ((sum * 10) + n * negtv);
		i++;
	}
	return (sum);
}
