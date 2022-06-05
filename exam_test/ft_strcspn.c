/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:02:59 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/05 16:20:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t i2;

    i = 0;
    i2 = 0;
    while (s[i] != '\0')
    {
        i2 = 0;
        while (reject[i2] != '\0')
        {
            if (s[i] == reject[i2])
                return (i);
            i2++;
        }
        i++;
    }
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}*/

size_t	ft_strcspn(const char *s, const char	*reject)
{
	size_t i;
	size_t j;

	i  = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

#include <stdio.h>

int main()
{
	const char s[] = "1234567890";
	const char s1[] = "abc";
	printf("%d", ft_strcspn(s, s1));
}

