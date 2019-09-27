#include "../includes/ft_ls.h"
#include <stdio.h>

static void		ft_init_test(char *name)
{
	struct dirent	*dir_read;
	DIR				*dir_open;
	struct stat		stat_file;

	stat(name, &stat_file);
	stat_file.st_mode &= S_IFMT;
	if (stat_file.st_mode & S_IFDIR)
	{
		dir_open = opendir(name);
		while ((dir_read = readdir(dir_open)) != NULL)
		{
			stat(dir_read->d_name, &stat_file);
			stat_file.st_mode &= S_IFMT;
			if (stat_file.st_mode & S_IFDIR)
			{
				ft_strcpy(name, dir_read->d_name);
				ft_init_test(name);
			}
		}
	}
	else
		ft_printf("name = %s\n", name);

}

int				main(int ac, char **av)
{
	int				i;

	i = 0;
	if (ac == 1)
	{
		ft_printf("fuck\n");
		return (1);
	}
	while (++i < ac)
		ft_init_test(av[i]);
	return (0);
}
