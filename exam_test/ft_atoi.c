/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:07:20 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/05 18:28:47 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int num;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = str[i] - 48;
		res = res * 10 + num;
		i++;
	}
	return (res * sign);
}
#include <stdlib.h>

int main()
{
	char s[] = "  -9 1ii23";
	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}
