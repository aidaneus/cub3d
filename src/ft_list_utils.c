#include "../includes/cub3d.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*b;

	b = *lst;
	while (b)
	{
		a = b->next;
		if (del)
		{
			del(b->content);
		}
		free(b);
		b = a;
	}
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	t_list	*l;
	int		a;

	l = lst;
	a = 0;
	while (l)
	{
		a++;
		l = l->next;
	}
	return (a);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	l = ft_lstlast(*lst);
	l->next = new;
}
