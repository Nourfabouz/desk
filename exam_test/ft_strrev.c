/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:50:18 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/05 17:05:54 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strrev(char *str)
{
	char tmp;
	int i ;
	int len;

	len = strlen(str) - 1;
	i = 0;
	while (i <= len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int	main()
{
	char s[] = "Victorious";
	printf("%s", ft_strrev(s));
}
