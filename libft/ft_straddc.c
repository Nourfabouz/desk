/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:26:32 by fabou-za          #+#    #+#             */
/*   Updated: 2022/05/18 15:26:36 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_straddc(char *str, char c)
{
    char    *add;
    int     i;

    if (!c)
        return (NULL);
    if (!str)
        return (ft_char_to_str(c));
    add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
    if (!add)
    {
        free(str);
        return (NULL);
    }
    i = -1;
    while (str[++i])
        add[i] = str[i];
    free(str);
    add[i++] = c;
    add[i] = '\0';
    return (add);
}
