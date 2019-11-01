#include "../includes/ft_ls.h"

void			ft_type(t_ls *file)
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

void			ft_rights(t_ls *file)
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

void			ft_link_ug_size_time_name(t_ls *file, t_parse v_parse)
{
	ft_printf("%*d ",v_parse.max_links, file->st_nlink);
	ft_printf("%-*s ", v_parse.max_uid, getpwuid(file->st_uid)->pw_name);
	ft_printf(" %-*s ", v_parse.max_gid, getgrgid(file->st_gid)->gr_name);
	if ((S_ISCHR(file->st_mode) || S_ISBLK(file->st_mode)))
	{
		ft_printf("  %*d,", v_parse.max_major, major(file->st_rdev));
		ft_printf(" %*d ", v_parse.max_minor, minor(file->st_rdev));
	}
	else
		ft_printf(" %*d ", v_parse.max_size, file->st_size);
	ft_printf(" %.12s ", ctime(&file->time) + 4);
	ft_printf("%s", file->name);
}
