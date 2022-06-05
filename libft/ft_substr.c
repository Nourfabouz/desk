/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:46:59 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/08 14:45:37 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned long	i;
	unsigned long	j;
	unsigned long	lens;

	if (s == NULL)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		len = 0;
	if (len > (lens - start))
		len = lens - start;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
