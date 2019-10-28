#include "../includes/ft_ls.h"

int		ft_max_len(t_list **begin_list, int opt)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (!(opt & A_LS) && ls_tmp->name[0] == '.')
			list_tmp = list_tmp->next;
		if (!list_tmp)
			break ;
		if ((int)ft_strlen(ls_tmp->name) > max_len)
			max_len = ft_strlen(ls_tmp->name);
		list_tmp = list_tmp->next;
	}
	return (max_len);
}

void	ft_simple_display(t_list **begin_list, int opt, int max_len)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;

	list_tmp = *begin_list;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (!(opt & A_LS) && ls_tmp->name[0] == '.')
			list_tmp = list_tmp->next;
		if (!list_tmp)
			break ;
		ft_printf("%-*s", max_len, ls_tmp->name);
		if (max_len * ft_lstcount(begin_list) < SIZE_M && list_tmp->next)
			ft_putchar('\n');
		list_tmp = list_tmp->next;
		if (!list_tmp)
			ft_printf("\n");
	}
}
