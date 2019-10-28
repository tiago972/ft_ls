#include "../includes/ft_ls.h"

void	ft_clean_mem(t_list **begin_list)
{
	t_list		*tmp;
	t_ls		*file_tmp;

	while (*begin_list)
	{
		file_tmp = (t_ls *)(*begin_list)->content;
		ft_strdel(&file_tmp->name);
		ft_strdel(&file_tmp->full_path);
		tmp = (*begin_list)->next;
		ft_memdel(begin_list);
		ft_memdel(&file_tmp);
		*begin_list = tmp;
	}
}
