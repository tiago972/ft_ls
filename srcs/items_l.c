#include "../includes/ft_ls.h"

void	ft_type(t_ls *file)
{
	file->st_mode &= S_IFMT;
	if (S_ISREG(
}
