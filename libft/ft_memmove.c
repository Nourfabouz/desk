/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:59:25 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/06 19:23:44 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *) dst;
	src1 = (unsigned char *) src;
	if (dst1 < src1)
	{
		i = 0;
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else if (dst1 > src1)
	{
		i = 0;
		while (i < len)
		{
			dst1[len - 1 - i] = src1[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
