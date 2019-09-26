/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:36:00 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/08 16:10:55 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_pad_nbr(t_printf *v_printf, uintmax_t uintarg)
{
	while (!(v_printf->flags & ZERO) && !(v_printf->flags & MINUS)
			&& --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & X))
		ft_buff(v_printf, "0x", 2);
	else if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & XX))
		ft_buff(v_printf, "0X", 2);
	else if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & O))
		ft_buff(v_printf, "0", 1);
	else if (uintarg == 0 && v_printf->flags & POUND && v_printf->conv & O
			&& v_printf->prec < 0 && v_printf->flags & DOT)
		ft_buff(v_printf, "0", 1);
	while ((v_printf->flags & ZERO)
			&& --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
}

void		ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt)
{
	uintmax_t	len;

	opt ? 0 : (v_printf->power = 20);
	v_printf->power = ft_log(ft_abs(int_arg), 10);
	len = v_printf->flags & DOT ? ft_max((int)v_printf->power, v_printf->prec)
		: (int)v_printf->power;
	if (int_arg != 0 || v_printf->prec > 0)
		v_printf->width -= len;
	v_printf->prec -= v_printf->power;
	if (int_arg < 0 || (int_arg == 0 && !(v_printf->flags & DOT)))
		v_printf->width--;
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP) && int_arg >= 0)
			v_printf->width--;
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && int_arg >= 0)
	{
		v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
			: ft_buff(v_printf, " ", 1);
		v_printf->width--;
	}
}
