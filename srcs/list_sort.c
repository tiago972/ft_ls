#include "../includes/ft_ls.h"

static void		ft_swap(void **a, void	**b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_ascii(t_list **begin_list, int opt)
{
	t_ls	*ls_tmp;
	t_ls	*ls_tmp2;
	t_list	*list_tmp;
	t_list	*list_tmp2;

	list_tmp = *begin_list;
	while (list_tmp->next && (list_tmp2 = list_tmp->next))
	{
		while (list_tmp2 && (ls_tmp2 = (t_ls *)list_tmp2->content))
		{
			ls_tmp = (t_ls *)list_tmp->content;
			if (!(opt & R_LS) && ft_strcmp(ls_tmp->name, ls_tmp2->name) > 0)
			{
				ft_swap(&list_tmp->content, &list_tmp2->content);
				list_tmp2 = list_tmp->next;
			}
			else if ((opt & R_LS) && ft_strcmp(ls_tmp->name, ls_tmp2->name) < 0)
			{
				ft_swap(&list_tmp2->content, &list_tmp->content);
				list_tmp2 = list_tmp->next;
			}
			else
				list_tmp2 = list_tmp2->next;
		}
		list_tmp = list_tmp->next;
	}
}

void	ft_sort_time(t_list **begin_list, int opt)
{
	t_ls	*ls_tmp;
	t_ls	*ls_tmp2;
	t_list	*list_tmp;
	t_list	*list_tmp2;

	list_tmp = *begin_list;
	while (list_tmp->next && (list_tmp2 = list_tmp->next))
	{
		while (list_tmp2 && (ls_tmp2 = (t_ls *)list_tmp2->content))
		{
			ls_tmp = (t_ls *)list_tmp->content;
			if (!(opt & R_LS) && (ls_tmp2->st_mtimespec > ls_tmp->st_mtimespec))
			{
				ft_swap(&list_tmp->content, &list_tmp2->content);
				list_tmp2 = list_tmp->next;
			}
			else if ((opt & R_LS)
					&& (ls_tmp->st_mtimespec > ls_tmp2->st_mtimespec))
			{
				ft_swap(&list_tmp2->content, &list_tmp->content);
				list_tmp2 = list_tmp->next;
			}
			else
				list_tmp2 = list_tmp2->next;
		}
		list_tmp = list_tmp->next;
	}
}
