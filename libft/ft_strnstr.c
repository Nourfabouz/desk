/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:35:16 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/13 21:24:27 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	lenneedle;
	unsigned long	i;
	int				cmpr;
	char			*stack;

	lenneedle = ft_strlen(needle);
	stack = (char *) haystack;
	i = 0;
	if (needle[0] == '\0')
		return (stack);
	while (i < len && stack[i])
	{
		if (stack[i] == needle[0] && len - i >= lenneedle)
		{
			cmpr = ft_strncmp((stack + i), needle, lenneedle);
			if (cmpr == 0)
				return (stack + i);
		}
		i++;
	}
	return (NULL);
}
