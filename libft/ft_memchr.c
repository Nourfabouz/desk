/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:47:47 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/06 17:46:28 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	crt;
	size_t			i;

	str = (unsigned char *) s;
	crt = (unsigned char ) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == crt)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
