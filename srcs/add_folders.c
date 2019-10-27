#include "../includes/ft_ls.h"

void	ft_dispath_opening(t_list **begin_list, int opt)
{
	if (opt & L)
		ft_rec_opening(begin_list, opt);
//	else
//		ft_opening(begin_list, opt);
}

static void		ft_rec_opening(t_list **begin_list, int opt)
{
	t_list		*l_tmp;
	t_ls		*ls_tmp;

	(void)opt;
	l_tmp = *begin_list;
	while (l_tmp)
	{
		ls_tmp = (t_ls *)l_tmp->content;
		if (S_ISDIR(ls_tmp->st_mode))
		{
			l_tmp = ft_readdir(l_tmp, ls_tmp);
			ft_debog(&l_tmp);
			ft_rec_opening(&l_tmp, opt);
			//ft_clean_mem(&l_tmp);
		}
	//	else
	//		ft_printf("not dir: name = %s\n", ls_tmp->name);
		l_tmp = l_tmp->next;
	}
}
