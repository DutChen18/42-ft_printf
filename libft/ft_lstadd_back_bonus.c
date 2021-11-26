#include "libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		lst = &ft_lstlast(*lst)->next;
	*lst = new;
}
