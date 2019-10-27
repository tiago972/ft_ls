#include "../includes/ft_ls.h"

void	ft_ls_error(char *str, int error)
{
	if (error == USAGE)
	{
		ft_printf_fd(2, "ft_ls: illegal option -- %s\n", str);
		ft_printf_fd(2, "usage: ft_ls [-alRrt] [file ...]\n");
		exit(EXIT_FAILURE);
	}
	//cal ft_del, NPO de rajouter begin_list en arg;
}
