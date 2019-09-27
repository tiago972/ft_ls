#include "../libft/libft.h"
#include "../includes/ft_ls.h"

void	ft_parse_name(char *name, t_ls *v_ls)
{
	char	tmp;
	int		i;

	if (!name)
		return ;
	i = 0;
	while (name[i + 1])
	{
		tmp = name[i];
		name[i] = name[i + 1];
		name[i + 1] = tmp;
		i++;
	}
	v_ls->name = ft_strdup(name);
	v_ls->name[ft_strlen(vs_len->name) - 2] = '\0';
}

void	ft_get_full_path(t_ls *v_ls)
{
}

void	ft_add_dir(t_ls *v_ls, t_list **begin_list)
{
	t_ls			v_ls;
	t_list			*tmp;
	DIR				*d_open;
	struct dirent	*d_read;

	tmp = *begin_list;
	ft_bzero(&v_ls, sizeof(v_files));
	ft_bzero(&(v_ls.full_path), PATH_MAX);
	ft_parse_name(name, &v_ls);
	ft_get_full_path(&v_ls);
	while (tmp)
		tmp->next;
	d_open = opendir(v_ls->name);
	while ((d_read = readdir(d_open)) != NULL)
		ft_add_file(d_read->name, begin_list);
}

void	ft_add_file(char *name, t_list **begin_list)
{
	t_ls			v_ls;
	struct stat		f_stat;
	t_list			*tmp;

	tmp = *begin_list;
	ft_bzero(&v_ls, sizeof(v_files));
	ft_bzero(&(v_ls.full_path), PATH_MAX);
	ft_parse_name(name, &v_ls);
	ft_get_full_path(&v_ls);
	stat(v_ls.path, &f_stat);
	f_stat.st_mode &= S_IMFT;
	if (f_stat.st_mode & S_ISDIR)
	{
		ft_add_dir(&v_ls, begin_list);
		return ;
	}
	while (tmp)
		tmp = tmp->next;
	tmp = lstnew(&v_ls, sizeof(t_ls));
	ft_lstadd(begin_list, tmp);
}
