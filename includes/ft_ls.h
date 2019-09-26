#ifndef FT_LS_H
# define FT_LS_H

# define A (1 << 0)
# define L (1 << 1)
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
#include <limits>

typedef struct		s_ls
{
	char			full_path[PATH_MAX];
	blkcnt_t		blocks;
	mode_t			mode;
	nlink_t			nb_link;
	uid_t			uid;
	gid_t			guid;
	off_t			size;
	dev_t			st_rdev;
	time_t			time;
	long			ntime;
	char			*name;
	char			full_path[PATH_MAX];
}					t_ls;

int		ft_parse_opt(int ac, char **av, int *opt);
void	ft_init(char **av, t_list **begin_list, int ac, int first);
void	ft_add_file(char *path, t_list **begin_list);

#endif
