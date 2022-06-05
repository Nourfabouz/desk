/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:44:45 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/02 16:49:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;
	t_list	*last;

	if (alst == NULL || new == NULL)
		return ;
	p = *alst;
	last = NULL;
	while (p != NULL)
	{
		last = p;
		p = p->next;
	}
	if (last)
		last->next = new;
	else
		*alst = new;
}
