#include "../includes/ft_ls.h"

static	t_list	*ft_readdir(t_ls *file, int opt)
{
	DIR				*o_dir;
	struct dirent	*dir_file;
	t_list			*begin_list;

	begin_list = NULL;
	if (!(o_dir = opendir(file->full_path)))
	{
		ft_ls_error(file->name, ERRNO);
		return (NULL);
	}
	while ((dir_file = readdir(o_dir)) != NULL)
	{
		if (dir_file->d_name[0] != '.')
			ft_add_to_list(&begin_list, dir_file->d_name, file->full_path);
		else if (dir_file->d_name[0] == '.' && (opt & A_LS)
				&& ft_strcmp(dir_file->d_name, ".") != 0)
			ft_add_to_list(&begin_list, dir_file->d_name, file->full_path);
	}
	closedir(o_dir);
	return (begin_list);
}

void			ft_rec_opening(t_list **begin_list, int opt, int start)
{
	t_list		*list_tmp;
	t_ls		*ls_tmp;
	t_list		*new_folder;

	list_tmp = *begin_list;
	new_folder = NULL;
	if (!start && !(opt & REC_LS))
		return ;
	if (start)
		ft_dispatch_opt(begin_list, opt);
	while (list_tmp)
	{
		ls_tmp = (t_ls *)list_tmp->content;
		if (S_ISDIR(ls_tmp->st_mode) && (start 
			|| (ft_strcmp(ls_tmp->name, ".") && ft_strcmp(ls_tmp->name, ".."))))
		{
			if ((new_folder = ft_readdir(ls_tmp, opt)))
			{
				ft_dispatch_opt(&new_folder, opt);
				ft_rec_opening(&new_folder, opt, 0);
				ft_clean_mem(&new_folder);
			}
		}
		list_tmp = list_tmp->next;
	}
}
