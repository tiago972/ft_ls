/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:00:09 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:13:53 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"

void		ft_flush(t_printf *v_printf)
{
	if (v_printf->col > 0)
		ft_printcol(v_printf);
	write(v_printf->fd, v_printf->buff, v_printf->ret_progress);
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	v_printf->ret_tot += v_printf->ret_progress;
	v_printf->ret_progress = 0;
	if (v_printf->col > 0)
		write(v_printf->fd, "\033[m", 3);
}

void			ft_buff(t_printf *v_printf, char *str, int n)
{
	int		tmp;

	if (v_printf->ret_progress == BUFF_SIZE)
		ft_flush(v_printf);
	while (str && n > (BUFF_SIZE - v_printf->ret_progress))
	{
		tmp = BUFF_SIZE - v_printf->ret_progress;
		ft_strncat(v_printf->buff, str, tmp);
		str += tmp;
		n -= tmp;
		v_printf->ret_progress += tmp;
		ft_flush(v_printf);
	}
	ft_strncat(v_printf->buff, str, n);
	v_printf->ret_progress += n;
	if (*str == 0 || v_printf->col > 0)
		ft_flush(v_printf);
}

static void		ft_reinit_struct(t_printf *v_printf)
{
	v_printf->flags = 0;
	v_printf->width = 0;
	v_printf->prec = -2;
	v_printf->conv = 0;
	v_printf->tmp = 0;
	v_printf->power = 0;
	v_printf->col = 0;
	v_printf->fd = 1;
}

void			ft_begin(t_printf *v_printf, const char *str,
				t_funptr funptr[14])
{
	ft_memset(v_printf, 0, sizeof(t_printf));
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	ft_inifunptr(funptr);
	v_printf->prec = -2;
	v_printf->str = (char *)str;
}

int				ft_printf(const char *str, ...)
{
	t_printf		v_printf;
	static t_funptr	funptr[14];

	if (!str)
		return (0);
	ft_begin(&v_printf, str, funptr);
	va_start(v_printf.ap, str);
	while (*(v_printf.str))
	{
		if (*(v_printf.str) && *(v_printf.str) == '%' && v_printf.str++)
		{
			ft_reinit_struct(&v_printf);
			ft_get_info(&v_printf, funptr);
		}
		else
		{
			ft_buff(&v_printf, v_printf.str, 1);
			v_printf.str++;
		}
	}
	if (v_printf.ret_progress > 0)
		ft_flush(&v_printf);
	va_end(v_printf.ap);
	return (v_printf.ret_tot);
}
