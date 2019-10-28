#include "../includes/ft_ls.h"

#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
void	ft_debog(t_list **begin_list)
{
	t_list	*tmp;
	t_ls	*tmp2;

	tmp = *begin_list;
	while (tmp)
	{
		tmp2 = ((t_ls *)tmp->content);
		ft_printf("name = %s\n", tmp2->name);
		tmp = tmp->next;
	}
}
