/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:01:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:38:09 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <limits.h>

long double		ft_get_arg_f(t_printf *v_printf)
{
	if (v_printf->flags & LF)
		return ((long double)va_arg(v_printf->ap, long double));
	else if (v_printf->flags & L)
		return ((long double)va_arg(v_printf->ap, double));
	else
		return ((long double)va_arg(v_printf->ap, double));
}

void			ft_get_mant(t_float *f)
{
	int		i;
	int		f_size;

	f_size = F_SIZE;
	i = 0;
	while (i < 64)
	{
		f->mant[f_size--] = f->ptr[i / CHAR_BIT] & (1U << (i % CHAR_BIT)) ?
			'1' : '0';
		i++;
	}
	f->mant[++f_size] = '.';
	if (f->f_arg != (long double)0)
		f->mant[--f_size] = '1';
}

void			ft_expand_mant(t_float *f)
{
	char	tmp;
	int		index;

	tmp = 0;
	index = 938;
	if (f->exp > 0)
		while (f->mant[index + 1] && f->exp > 0)
		{
			tmp = f->mant[index];
			f->mant[index] = f->mant[index + 1];
			f->mant[index + 1] = tmp;
			index++;
			f->exp--;
		}
	else if (f->exp < 0)
		while (index - 1 >= 0 && f->exp < 0)
		{
			tmp = f->mant[index];
			f->mant[index] = f->mant[index - 1];
			f->mant[index - 1] = tmp;
			f->exp++;
		}
}

void			ft_power_to_char(t_float *f, int power, int mant_firstnbr)
{
	int		ret;
	int		res_tmp;
	int		tmp_index;

	ret = 0;
	while (power > 0)
	{
		tmp_index = F_SIZE - 1;
		while (mant_firstnbr <= tmp_index)
		{
			res_tmp = ((f->tmp[tmp_index] - '0') * 2 + ret);
			ret = res_tmp / 10;
			f->tmp[tmp_index] = res_tmp % 10 + '0';
			tmp_index--;
		}
		power--;
	}
}

void			ft_calc_int(t_float *f)
{
	int		mant_index;
	int		i;
	int		mant_firstnbr;

	mant_index = ft_strlen_c(f->mant, '.') - 1;
	i = mant_index;
	mant_firstnbr = ft_where_is_not_0(f->mant, mant_index);
	while (i >= 0)
	{
		ft_memset(f->tmp, '0', F_SIZE);
		if (mant_index - i > 0 && f->mant[i] != '0')
		{
			f->tmp[F_SIZE - 1] = '1';
			ft_power_to_char(f, mant_index - i, mant_firstnbr);
			ft_add_in_char(f);
		}
		else if (mant_index - i == 0 && f->mant[i] != '0')
		{
			f->tmp[F_SIZE - 1] = '1';
			ft_add_in_char(f);
		}
		i--;
	}
	ft_to_front(f);
	f->res[f->int_size] = '.';
}
