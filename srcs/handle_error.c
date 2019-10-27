#include "../includes/ft_ls.h"

void	ft_ls_error(char *str, int error)
{
	if (error == USAGE)
	{
		ft_printf_fd(2, "ft_ls: illegal option -- %s\n", str);
		ft_printf_fd(2, "usage: ft_ls [-alRrt] [file ...]\n");
		exit(EXIT_FAILURE);
	}
	else if (error == ERRNO)
	{
		if (str)
			ft_printf_fd(2, "ft_ls: %s: %s\n", str, strerror(errno));
		else
			ft_printf_fd(2, "ft_ls: %s\n", strerror(errno));
	}	
}
