#include "../includes/ft_ls.h"

void		ft_print_path(char *path, int opt, int start)
{
	if (opt & REC_LS)
	{
		if (!start)
			ft_printf("\n%s:\n", path);
	}
}

int			ft_max_len(t_list **begin_list, int opt)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if ((!(opt & A_LS) && ls_tmp->name[0] == '.') || ls_tmp->name[0] =='/')
			list_tmp = list_tmp->next;
		if (!list_tmp)
			break ;
		if ((int)ft_strlen(ls_tmp->name) > max_len)
			max_len = ft_strlen(ls_tmp->name);
		list_tmp = list_tmp->next;
	}
	return (max_len);
}

void		ft_simple_display(t_list **begin_list, int opt, int max_len)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;

	list_tmp = *begin_list;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if ((!(opt & A_LS) && ls_tmp->name[0] == '.') || ls_tmp->name[0] =='/')
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
	t_list	*list_tmp;
	t_ls	*ls_tmp;

	list_tmp = *begin_list;
	ft_printf("total: %Ld\n", ft_count_blocks(begin_list));
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		/*ft_type();
		ft_rights();
		ft_acl();
		ft_nbfile();
		ft_uid();
		ft_gid();
		ft_size();
		ft_time();
		ft_name();*/
		list_tmp = list_tmp->next;
	}
}
