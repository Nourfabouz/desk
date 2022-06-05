#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void	*content)
{
	t_list	*head;

	head = (t_list *) malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

int main()
{
	char s[] = "faiza";
	t_list	*p = ft_lstnew((void *) s);
	printf("%s", p->content);
}
