/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:39:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:40:52 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"

int			ft_where_is_not_0(char *str, int index)
{
	int	i;

	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] != '0')
			return (i);
		i++;
	}
	return (F_SIZE);
}

void		ft_add_in_char(t_float *f)
{
	int		i;
	int		ret;
	int		tmp;
	int		lim;

	lim = ft_min(ft_where_is_not_0(f->tmp, F_SIZE),
			ft_where_is_not_0(f->res, F_SIZE));
	i = 1;
	ret = 0;
	while (i <= lim)
	{
		tmp = (f->res[F_SIZE - i] - '0') + (f->tmp[F_SIZE - i] - '0') + ret;
		ret = tmp / 10;
		f->res[F_SIZE - i] = tmp % 10 + '0';
		i++;
	}
}

void		ft_negpower_to_char(t_float *f, int power)
{
	intmax_t	den;
	intmax_t	num;
	intmax_t	tmp;
	int			i;

	num = 10;
	i = 0;
	if ((den = ft_iterative_power(2, power)) == -1)
		return ;
	while (i < F_SIZE)
	{
		tmp = 1;
		while (tmp * den < num)
			tmp++;
		if (tmp * den > num)
			tmp--;
		f->tmp[i] = tmp + '0';
		tmp = num - (tmp * den);
		if (tmp == 0)
			break ;
		num = tmp;
		num *= 10;
		i++;
	}
}

void		ft_add_dec_in_char(t_float *f)
{
	int		i;
	int		ret;
	int		tmp;

	i = 1;
	ret = 0;
	while (i <= F_SIZE)
	{
		tmp = (f->dec[F_SIZE - i] - '0') + (f->tmp[F_SIZE - i] - '0') + ret;
		ret = tmp / 10;
		f->dec[F_SIZE - i] = tmp % 10 + '0';
		i++;
	}
}

void		ft_calc_dec(t_float *f)
{
	int		mant_index;
	int		i;

	mant_index = ft_strlen_c(f->mant, '.') + 1;
	i = 1;
	while (mant_index < F_SIZE)
	{
		ft_memset(f->tmp, '0', F_SIZE);
		if (f->mant[mant_index] == '1')
		{
			ft_negpower_to_char(f, i);
			ft_add_dec_in_char(f);
		}
		i++;
		mant_index++;
	}
}
