#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*p;
	t_list	*last;

	p = lst;
	if (lst == NULL)
		return NULL;
	while (p != NULL)
	{
		last = p;
		p = p->next;
	}
	return (last);
}
int main()
{
	t_list	*head;
	t_list	*p;
	t_list  *plast;

	char s[] = "fz";
	char s1[] = "abou";
	head = ft_lstnew((void  *) s);
    p = ft_lstnew((void *) s1);
    head->next = p;
    plast = ft_lstlast(head);
    printf("%s", plast->content);
}
