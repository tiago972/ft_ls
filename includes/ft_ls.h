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
typedef struct	s_file
{
	int		folder;
	char*	name;
	int		access;
}				t_file;
#include <stdio.h>
#endif
