#include "../includes/ft_ls.h"

#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
void	ft_debog(t_list **begin_list)
{
	t_list	*tmp;
	t_ls	*tmp2;
	time_t	today;

	time (&today);
	tmp = *begin_list;
	while (tmp)
	{
		tmp2 = ((t_ls *)tmp->content);
		ft_printf("name = %s, nblocks %Ld\n", tmp2->name, tmp2->st_blocks);
		tmp = tmp->next;
	}
}
