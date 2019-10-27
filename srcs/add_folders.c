#include "../includes/ft_ls.h"

void	ft_dispath_opening(t_list **begin_list, int opt)
{
	if (opt & L)
		ft_rec_opening(begin_list, opt);
	else
		ft_opening(begin_list, opt);
}
