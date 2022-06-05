/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:08 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:26 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	dstlen;
	unsigned long	srclen;
	unsigned long	count;

	dstlen = 0;
	while (dst[dstlen] != '\0')
		dstlen++;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	count = 0;
	while ((count + dstlen + 1 < dstsize) && src[count])
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + srclen);
}
