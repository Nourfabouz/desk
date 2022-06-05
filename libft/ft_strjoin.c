/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:18:09 by fabou-za          #+#    #+#             */
/*   Updated: 2021/11/27 17:00:04 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*dst;
	size_t	i;
	size_t	len;
	size_t	lentotal;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) malloc((lentotal + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	dst = (char *) s1;
	i = 0;
	while (dst[i])
	{
		ptr[i] = dst[i];
		i++;
	}
	ptr[i] = '\0';
	len = ft_strlcat(ptr, s2, lentotal + 1);
	return (ptr);
}
