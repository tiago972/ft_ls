/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:16:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/06 14:37:09 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>
#include "../../includes/libft.h"

void	ft_getcol(t_printf *v_printf)
{
	int		tmp;

	tmp = 0;
	while ((tmp = ft_strlen_c("RBGY", *(v_printf->str))) > -1
			&& v_printf->str++)
		if (*(v_printf->str) == '}' && v_printf->str++)
			v_printf->col |= (1 << tmp);
}

void	ft_inicol(t_col col[4])
{
	col[0].nb |= RED;
	ft_strcpy(col[0].col, "\033[31m");
	col[1].nb |= BLUE;
	ft_strcpy(col[1].col, "\033[34m");
	col[2].nb |= GREEN;
	ft_strcpy(col[2].col, "\033[32m");
	col[3].nb |= YELLOW;
	ft_strcpy(col[3].col, "\033[33m");
}

void	ft_printcol(t_printf *v_printf)
{
	t_col	col[4];
	int		i;

	ft_inicol(col);
	i = -1;
	while (++i < 4)
		if (v_printf->col == col[i].nb)
		{
			write(1, col[i].col, 5);
			return ;
		}
}
