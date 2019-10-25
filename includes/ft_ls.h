#ifndef FT_LS_H
# define FT_LS_H

# define A (1 << 0)
# define L_LS (1 << 1)
# define REC (1 << 2)
# define R (1 << 3)
# define T (1 << 4)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "../libft/includes/libft.h"
#include "../libft/ft_printf/includes/ft_printf.h"
#include <errno.h>
#include <limits.h>

typedef struct		s_ls
{
	char			full_path[PATH_MAX];
	struct stat		t_stat;
}					t_ls;

void	ft_add_file(t_list **begin_list, char *path, char *name);
int		ft_get_full_path(char *path, char *name, char full_path[PATH_MAX]);
t_ls	*ft_initialize(t_list **begin_list, char *path, char *name);

#include <stdio.h>
#endif
