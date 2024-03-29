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
#include <pwd.h>
#include <uuid/uuid.h>
 #include <grp.h>

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

typedef struct			s_parse
{
	int		max_links;
	int		max_uid;
	int		max_gid;
	int		max_major;
	int		max_minor;
	int		max_size;
	int		max_name;
}						t_parse;

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
int						ft_max_len_name(t_list **begin_list);
void					ft_simple_display(t_list **begin_list, int start);
void					ft_full_display(t_list **begin_list);
void					ft_print_path(char *begin_list, int opt,
						int start);
void					ft_type(t_ls *file);
void					ft_rights(t_ls *file);
void					ft_all_max(t_parse *v_parse, t_list **begin_list);
void					ft_link_ug_size_time_name(t_ls *file, t_parse v_parse);
int						ft_max_links(t_list **begin_list);
int						ft_max_len_uid(t_list **begin_list);
int						ft_max_len_gid(t_list **begin_list);
int						ft_max_size(t_list **begin_list);
int						ft_max_major(t_list **begin_list);
int						ft_max_minor(t_list **begin_list);
void	ft_debog(t_list **begin_list);
#endif
