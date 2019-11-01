#include "../includes/ft_ls.h"

void		ft_print_path(char *path, int opt, int start)
{
	if (opt & REC_LS)
	{
		if (!start)
			ft_printf("\n%s:\n", path);
	}
}

void		ft_simple_display(t_list **begin_list, int start)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = ft_max_len_name(begin_list);
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (start)
			while (list_tmp && S_ISDIR(((t_ls *)list_tmp->content)->st_mode))
				list_tmp = list_tmp->next;
		if (!list_tmp)
			break ;
		ft_printf("%-*s ", max_len, ls_tmp->name);
		if ((((max_len * ft_lstcount(begin_list)) > SIZE_M))
				&& list_tmp->next)
			ft_putchar('\n');
		list_tmp = list_tmp->next;
		if (!list_tmp)
			ft_printf("\n");
	}
}

static long	ft_count_blocks(t_list **begin_list)
{
	long	nb_blocks;
	t_list	*list_tmp;

	list_tmp = *begin_list;
	nb_blocks = 0;
	while (list_tmp)
	{
		nb_blocks += ((t_ls *)list_tmp->content)->st_blocks;
		list_tmp = list_tmp->next;
	}
	return (nb_blocks);
}

void		ft_full_display(t_list **begin_list)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	t_parse		v_parse;

	list_tmp = *begin_list;
	ft_bzero(&v_parse, sizeof(t_parse));
	ft_all_max(&v_parse, begin_list);
	// debog
		//ft_debog(begin_list);
	//if (S_ISDIR(((t_ls *)(*begin_list)->content)->st_mode))
		ft_printf("total: %Ld\n", ft_count_blocks(begin_list));
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		ft_type(ls_tmp);
		ft_rights(ls_tmp);
		ft_link_ug_size_time_name(ls_tmp, v_parse);
		ft_printf("\n");
		list_tmp = list_tmp->next;
	}
}
