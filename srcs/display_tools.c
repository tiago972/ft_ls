#include "../includes/ft_ls.h"

int			ft_max_len_name(t_list **begin_list)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if ((int)ft_strlen(ls_tmp->name) > max_len)
			max_len = ft_strlen(ls_tmp->name);
		list_tmp = list_tmp->next;
	}
	return (max_len);
}

int			ft_max_len_uid(t_list **begin_list)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (((int)ft_strlen(getpwuid(ls_tmp->st_uid)->pw_name)) > max_len)
			max_len = ft_strlen(getpwuid(ls_tmp->st_uid)->pw_name);
		list_tmp = list_tmp->next;
	}
	return (max_len);
}

int			ft_max_len_gid(t_list **begin_list)
{
	t_list	*list_tmp;
	t_ls	*ls_tmp;
	int		max_len;

	list_tmp = *begin_list;
	max_len = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (((int)ft_strlen(getgrgid(ls_tmp->st_gid)->gr_name)) > max_len)
			max_len = ft_strlen(getgrgid(ls_tmp->st_gid)->gr_name);
		list_tmp = list_tmp->next;
	}
	return (max_len);
}

int			ft_max_links(t_list **begin_list)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	int			max_links;

	list_tmp = *begin_list;
	max_links = 0;
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (ft_log((uintmax_t)ls_tmp->st_nlink, 10) > (uintmax_t)max_links)
			max_links = ft_log((uintmax_t)ls_tmp->st_nlink, 10);
		list_tmp = list_tmp->next;
	}
	return (max_links);
}

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
