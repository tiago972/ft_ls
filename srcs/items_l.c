#include "../includes/ft_ls.h"

void	ft_type(t_ls *file)
{
	if (S_ISREG(file->st_mode))
		ft_printf("-");
	else if  (S_ISDIR(file->st_mode))
		ft_printf("d");
	else if  (S_ISCHR(file->st_mode))
		ft_printf("c");
	else if  (S_ISBLK(file->st_mode))
		ft_printf("b");
	else if  (S_ISFIFO(file->st_mode))
		ft_printf("p");
	else if  (S_ISLNK(file->st_mode))
		ft_printf("l");
	else if  (S_ISSOCK(file->st_mode))
		ft_printf("s");
	else
		ft_printf("-");
}

void	ft_rights(t_ls *file)
{
	(S_IRUSR & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWUSR & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXUSR & file->st_mode) ? ft_printf("x") : ft_printf("-");
	(S_IRGRP & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWGRP & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXGRP & file->st_mode) ? ft_printf("x") : ft_printf("-");
	(S_IROTH & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWOTH & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXOTH & file->st_mode) ? ft_printf("x") : ft_printf("-");
	//if ((S_ISCHR(file->st_mode) || S_ISBLK(file->st_mode)))
	//	ft_printf(" ");
	//else
		ft_printf("  ");
}

void	ft_link_ug_size_time_name(t_ls *file, t_list **begin_list)
{
	int		max;

	max = ft_max_links(begin_list);
	ft_printf("%*d ", max, file->st_nlink);
	max = ft_max_len_uid(begin_list);
	ft_printf("%-*s ", max, getpwuid(file->st_uid)->pw_name);
	max = ft_max_len_gid(begin_list);
	ft_printf(" %-*s ", max, getgrgid(file->st_gid)->gr_name);
	if ((S_ISCHR(file->st_mode) || S_ISBLK(file->st_mode)))
	{
		max = ft_max_major(begin_list);
		ft_printf("  %*d,", max, major(file->st_rdev));
		max = ft_max_minor(begin_list);
		ft_printf(" %*d ", max, minor(file->st_rdev));
	}
	else
	{
		max = ft_max_size(begin_list);
		ft_printf(" %*d ", max, file->st_size);
	}
}
