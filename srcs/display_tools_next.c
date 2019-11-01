#include "../includes/ft_ls.h"

int		ft_max_size(t_list **begin_list)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	int			max_size;

	list_tmp = *begin_list;
	max_size = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (ft_log((uintmax_t)ls_tmp->st_size, 10) > (uintmax_t)max_size)
			max_size = ft_log((uintmax_t)ls_tmp->st_size, 10);
		list_tmp = list_tmp->next;
	}
	return (max_size);
}

int		ft_max_major(t_list **begin_list)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	int			max_major;

	list_tmp = *begin_list;
	max_major = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (ft_log(major(ls_tmp->st_rdev), 10) > (uintmax_t)max_major)
			max_major = (int)ft_log(major(ls_tmp->st_rdev), 10);
		list_tmp = list_tmp->next;
	}
	return (max_major);
}

int		ft_max_minor(t_list **begin_list)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	int			max_major;

	list_tmp = *begin_list;
	max_major = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (ft_log(minor(ls_tmp->st_rdev), 10) > (uintmax_t)max_major)
			max_major = (int)ft_log(minor(ls_tmp->st_rdev), 10);
		list_tmp = list_tmp->next;
	}
	return (max_major);
}
