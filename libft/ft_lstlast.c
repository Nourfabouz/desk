/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:46:07 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/07 18:28:50 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*p;
	t_list	*last;

	p = lst;
	last = NULL;
	if (lst == NULL)
		return (NULL);
	while (p != NULL)
	{
		last = p;
		p = p->next;
	}
	return (last);
}
