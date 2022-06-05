#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
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

void	changecont(void *s)
{
	int i;
	int len;

	char *p = (char *) s;

	len = 0;
	while (p[len])
		len++;
	i = 0;
	while (i < len)
	{
		p[i] = 'f';
		i++;
	}
}
void    ft_lstiter(t_list   *lst, void (*f)(void    *))
{
    if (lst == NULL)
        return ;
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

int main()
{
	char s[] = "faiza";
	t_list *p;
	p = ft_lstnew(s);
	ft_lstiter(p, &changecont);
	printf("%s", p->content);
}
