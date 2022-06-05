/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:46:25 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/07 17:32:15 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void *(*f)(void	*), void (*del)(void	*))
{
	void	*cont;
	t_list	*nlst;
	t_list	*head;
	t_list	*p;

	if (lst == NULL)
		return (NULL);
	cont = f(lst->content);
	nlst = ft_lstnew(cont);
	if (nlst == NULL)
		ft_lstclear(&head, del);
	head = nlst;
	p = head;
	lst = lst->next;
	while (lst)
	{
		cont = f(lst->content);
		nlst = ft_lstnew(cont);
		if (nlst == NULL)
			ft_lstclear(&head, del);
		p->next = nlst;
		p = p->next;
		lst = lst->next;
	}
	return (head);
}
