#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (ft_lstsize(lst->next) + 1);
}
