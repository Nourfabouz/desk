/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:38:44 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/06 17:07:50 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *s, int c)
{
	int		i;
	int		len;
	char	cr;

	len = 0;
	while (s[len] != '\0')
		len++;
	cr = (char) c;
	if (c == '\0')
		return ((char *) s + len);
	i = len - 1;
	while (i >= 0)
	{
		if (s[i] == cr)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
