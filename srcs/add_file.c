#include "../includes/ft_ls.h"

static int		ft_dot_path(t_ls *file, char *name)
{
	if (ft_strcmp(name, ".") == 0)
		if (!(file->full_path = ft_strdup("./")))
			return (0);
	if (ft_strcmp(name, "..") == 0)
		if (!(file->full_path = ft_strdup("../")))
			return (0);
	return (1);
}

static int		ft_get_full_path(t_ls *file, char *path, char *name)
{
	char	*tmp;

	if (ft_strlen(path) + ft_strlen(name) + 1 > PATH_MAX)
	{
		errno = ENAMETOOLONG;
		return (0);
	}
	if (name[0] == '.')
		return (ft_dot_path(file, name));
	if (!(tmp = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		return (0);
	(!*path) ? ft_memcpy(tmp, ".", 1) : ft_memcpy(tmp, path, ft_strlen(path));
	ft_strcat(tmp, "/");
	ft_strcat(tmp, name);
	if (!(file->full_path = ft_strdup(tmp)))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

static void		ft_init_struct(t_ls *file, char *name)
{
	t_stat		v_stat;

	if (!(file->name = ft_strdup(name)))
		ft_ls_error(NULL, ERRNO);
	if (lstat(file->full_path, &v_stat) == -1)
		ft_ls_error(name, ERRNO);
	file->st_uid = v_stat.st_uid;
}

void			ft_add_to_list(t_list **begin_list, char *name, char *path)
{
	t_ls	file;
	t_list	*tmp;

	tmp = *begin_list;
	if (!ft_get_full_path(&file, path, name))
		ft_ls_error(name, ERRNO);
	ft_init_struct(&file, name);
	while (tmp)
		tmp = tmp->next;
	if (!(tmp = ft_lstnew(&file, sizeof(t_ls))))
		ft_ls_error(NULL, ERRNO);
	ft_lstadd(begin_list, tmp);
	return ;
}
