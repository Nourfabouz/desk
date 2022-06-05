#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list  *ft_lstnew(void *content)
{
    t_list  *head;

    head = (t_list *) malloc(sizeof(t_list));
    if (head == NULL)
        return (NULL);
    head->content = content;
    head->next = NULL;
    return (head);
}

int	ft_lstsize(t_list	*lst)
{
	t_list	*p;
	int		len;

	if (lst == NULL)
		return (0);
	p = lst;
	len = 0;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return (len);
}

int	main(){
	t_list	*head;
	t_list	*p;
	t_list	*last;

	char s[] = "fz";
	char s1[] = "abou";
	char s2[] = "hassan";
	head = ft_lstnew((void	*) s);
	p = ft_lstnew((void	*) s1);
	last = ft_lstnew((void *) s2);
	head->next = p;
	p->next = last;
	int n = ft_lstsize(head);
	printf("%d", n);
}
