#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{

	struct dirent *pDirent;
	DIR *pDir;

	if (ac < 2) {
		printf ("Usage: testprog <dirname>\n");
		return 1;
	}
	pDir = opendir (av[1]);
	if (pDir == NULL) {
		printf ("Cannot open directory '%s'\n",av[1]);
		return 1;
	}

	while ((pDirent = readdir(pDir)) != NULL) {
		printf ("[%s]\n", pDirent->d_name);
	}
	closedir (pDir);
}
