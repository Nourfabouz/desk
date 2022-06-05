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

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}

int main(){
    t_list  *head;
    t_list  *p;
    t_list  *last;

    char s[] = "fz";
    char s1[] = "abou";
    char s2[] = "Zer";
    head = ft_lstnew((void  *) s);
    p = ft_lstnew((void *) s1);
    last = ft_lstnew((void *) s2);
    head->next = p;
    ft_lstadd_front(&head, last);
    printf("%s", head->content);
}
