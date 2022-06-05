/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:25:51 by fabou-za          #+#    #+#             */
/*   Updated: 2022/05/18 15:26:00 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_char_to_str(char c)
{
    char    *str;

    str = (char *)malloc(sizeof(char) * 2);
    if (!str)
        return (NULL);
    str[0] = c;
    str[1] = '\0';
    return (str);
}
