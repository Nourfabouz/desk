/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:45:23 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/07 15:15:01 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void	*))
{
	t_list	*p;
	t_list	*head;

	if (lst == NULL || *lst == NULL)
		return ;
	p = *lst;
	while (p)
	{
		head = p;
		del(p->content);
		p = p->next;
		free(head);
	}
	*lst = NULL;
}
