/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:44:20 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/09 18:23:15 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		len;
	int		pos;
	int		pos1;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	pos = i;
	len = (int) ft_strlen(s1);
	i = len - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	pos1 = i;
	len = pos1 - pos + 1;
	ptr = ft_substr(s1, pos, len);
	return (ptr);
}
