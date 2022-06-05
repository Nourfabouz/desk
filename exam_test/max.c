/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:51:48 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/05 19:05:13 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     max(int* tab, unsigned int len)
{
	unsigned int i = 1;
	if (!len)
		return (0);
	int max = tab[0];
	
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int main()
{
	int tab[] = {1, 2 ,3,9};
	printf ("%d", max(tab, 4));
}

