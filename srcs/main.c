#include "../includes/ft_ls.h"


static char *ft_test_parse(char *name)
{
	char	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (name[i + 1])
	{
		tmp = name[i];
		name[i] = name[i + 1];
		name[i + 1] = tmp;
		i++;
	}
	name[i + ft_strlen(name) - 2] = '\0';
	return (name);
}

int		main(int ac, char **av)
{
	int	i;
	struct dirent	*dir_read;
	DIR				*dir_open;
	struct stat		stat_file;
	char			*name;

	i = 1;
	if (ac == 1)
	{
		ft_printf("fuck\n");
		return (1);
	}
	while (i < ac)
	{
		name = ft_strnew(256);
		stat(av[i], &stat_file);
		stat_file.st_mode &= S_IFMT;
		if (stat_file.st_mode & S_IFDIR)
		{
			while (stat_file.st_mode & S_IFDIR)
			{
				dir_open = opendir(av[i]);
				while ((dir_read = readdir(dir_open)) != NULL)
				{
					name = dir_read->d_name;
					name = ft_test_parse(name);
					ft_printf("%s\n", name);
				}
				closedir(dir_open);
			}
		}
		else 
			ft_printf("??\n");
		i++;
	}
	return (0);
}
