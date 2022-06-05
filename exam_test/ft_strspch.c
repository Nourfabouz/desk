/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:21:05 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/05 16:38:50 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;

	while (s[i])
	{
		int j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return(i);
			j++;
		}
		i++;
	}
	return (i);
}

int main()
{
	const char s[] = "abcd";
	const char reject[] = "oiuy";

	printf ("%ld", ft_strcspn(s, reject));
}



