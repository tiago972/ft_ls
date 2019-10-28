#include "../includes/libft.h"

size_t	ft_lstcount(t_list **begin_list)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = *begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
