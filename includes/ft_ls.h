#ifndef FT_LS_H
# define FT_LS_H

# define A_LS (1 << 0)
# define L_LS (1 << 1)
# define REC_LS (1 << 2)
# define R_LS (1 << 3)
# define T_LS (1 << 4)
# define SIZE_M 85
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "../libft/includes/libft.h"
#include "../libft/ft_printf/includes/ft_printf.h"
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct			s_ls
{
	char			*full_path;
	char			*name;
	mode_t			st_mode;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	dev_t			st_rdev;
	time_t			time;
	nlink_t			st_nlink;
	blkcnt_t		st_blocks;
}						t_ls;

typedef struct	stat	t_stat;

enum					{USAGE, ERRNO};
int						ft_parse_opt(int ac, char **av, int *opt);
void					ft_add_to_list(t_list **begin_list,
						char *name, char *path);
void					ft_dispatch_opening(t_list **begin_list, int opt, 
						int start);
void					ft_ls_error(char *str, int error);
void					ft_clean_mem(t_list **begin_list);
void					ft_rec_opening(t_list **begin_list, int opt, int start);
void					ft_sort_ascii(t_list **begin_list, int opt);
void					ft_sort_time(t_list **begin_list, int opt);
void					ft_dispatch_opt(t_list **begin_list, int opt);
int						ft_max_len(t_list **begin_list, int opt);
void					ft_simple_display(t_list **begin_list, int opt,
						int max_len);
void	ft_debog(t_list **begin_list);
#endif
