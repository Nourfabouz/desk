#include <stdio.h>
#include <stdlib.h>

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

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

void	ft_lstadd_back(t_list	**alst, t_list	*new)
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

int main(){
    t_list  *head;
    t_list  *p;
    t_list  *last;

    char s[] = "fz";
    char s1[] = "abou";
    char s2[] = "Zer";
    head = (ft_lstnew((void  *) s));
    p = ft_lstnew((void *) s1);
    head->next = p;
	//head = NULL;
	last = ft_lstnew((void *) s2);
    ft_lstadd_back(&head, last);
    printf("%s", p->next->content);
}
