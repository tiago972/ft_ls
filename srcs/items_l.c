#include "../includes/ft_ls.h"

void	ft_type(t_ls *file)
{
	file->st_mode &= S_IFMT;
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
	file->st_mode ^= ~S_IFMT;
	(S_IRUSR & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWUSR & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXUSR & file->st_mode) ? ft_printf("x") : ft_printf("-");
	(S_IRGRP & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWGRP & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXGRP & file->st_mode) ? ft_printf("x") : ft_printf("-");
	(S_IROTH & file->st_mode) ? ft_printf("r") : ft_printf("-");
	(S_IWOTH & file->st_mode) ? ft_printf("w") : ft_printf("-");
	(S_IXOTH & file->st_mode) ? ft_printf("x") : ft_printf("-");
	ft_printf(" ");
}

void	ft_link_ug_size_time_name(t_ls *file)
{
	ft_printf("%-*u ", ft_max_links((unsigned)file->st_nlink);
}
