/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:29 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:48:11 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"

void		ft_to_front(t_float *f)
{
	int		i;
	int		j;
	char	tmp;

	i = ft_where_is_not_0(f->res, F_SIZE);
	if (i == F_SIZE)
	{
		f->int_size = 1;
		return ;
	}
	j = 0;
	f->int_size = F_SIZE - i;
	while (f->res[i])
	{
		tmp = f->res[i];
		f->res[i] = f->res[j];
		f->res[j] = tmp;
		i++;
		j++;
	}
}

void		ft_opt_pad_f(t_printf *v_printf, t_float *f, int opt, int i)
{
	if (opt == 1)
		ft_buff(v_printf, f->res, ft_strlen_c(f->res, '0'));
	if (opt == 0)
	{
		if (f->res[i] == '.' && v_printf->prec != 0 && i++)
			ft_buff(v_printf, ".", 1);
		ft_buff(v_printf, f->res + i, v_printf->prec);
		if (v_printf->flags & POUND && v_printf->prec == 0)
			ft_buff(v_printf, ".", 1);
	}
	if (v_printf->flags & MINUS && (v_printf->flags & PLUS ||
				v_printf->flags & SP) && f->sign != -1)
		v_printf->width--;
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (opt == 1 && v_printf->flags & MINUS && v_printf->width == 0)
		ft_buff(v_printf, " ", 1);
}

void		ft_if_f(t_float *f, t_printf *v_printf, int opt)
{
	if (opt == 1 && v_printf->flags & ZERO)
		v_printf->flags &= ~ZERO;
	if (f->sign == -1)
		v_printf->width--;
	if (f->sign == -1 && v_printf->flags & POUND
		&& (v_printf->flags & SP || v_printf->flags & PLUS)
		&& !(v_printf->flags & MINUS))
		v_printf->width++;
	if (f->sign == 1 && f->f_arg != (long double)0 && v_printf->flags & POUND
		&& (v_printf->flags & SP || v_printf->flags & PLUS)
		&& v_printf->width - (int)ft_strlen_c(f->res, '.') - 1 > v_printf->prec
		&& !(v_printf->flags & MINUS))
		v_printf->width--;
	if (f->f_arg == (long double)0 && v_printf->flags & POUND
		&& v_printf->flags & ZERO
		&& (v_printf->flags & PLUS || v_printf->flags & SP))
		v_printf->width--;
	if (opt == 0)
		v_printf->width -= (v_printf->prec + ft_strlen_c(f->res, '.') + 1);
}

void		ft_pad_f(t_printf *v_printf, t_float *f, int opt)
{
	int		i;

	i = 0;
	ft_if_f(f, v_printf, opt);
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP)
				&& f->sign == 1 && opt == 0)
			v_printf->width--;
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
		if (opt == 1 && v_printf->width == 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && f->sign == 1
			&& f->f_arg == f->f_arg)
		v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
			: ft_buff(v_printf, " ", 1);
	if (f->sign == -1 && opt == 0)
		ft_buff(v_printf, "-", 1);
	while ((v_printf->flags & ZERO) && opt == 0 && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (opt == 0 && f->res[i] && f->res[i] != '.' && ++i)
		ft_buff(v_printf, f->res + i - 1, 1);
	ft_opt_pad_f(v_printf, f, opt, i);
}
