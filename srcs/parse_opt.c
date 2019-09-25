#include "../libft/libft.h"
#include "../includes/ft_ls.h"

int		ft_parse_opt(int ac, char **av, int *opt)
{
	int		tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
			return ;
		while (av[i][j] && (tmp = ft_strlen_c("alRt", av[i][j])) > -1)
		{
			*opt |= (1 << tmp);
			j++;
		}
		i++;
	}
	return (i);
}
