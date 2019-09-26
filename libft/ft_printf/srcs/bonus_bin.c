/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:35:58 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/08 16:56:19 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <limits.h>

void		*ft_malloc_tmp(t_printf *v_printf)
{
	void	*tmp;

	tmp = NULL;
	if (v_printf->conv & C)
		if (!(tmp = malloc(sizeof(char))))
			return (0);
	if (v_printf->conv & D || v_printf->conv & U)
		if (!(tmp = malloc(sizeof(intmax_t))))
			return (0);
	if (v_printf->conv & F)
		if (!(tmp = malloc(sizeof(long double))))
			return (0);
	return (tmp);
}

void		*ft_get_arg_b(t_printf *v_printf)
{
	void		*tmp;

	tmp = ft_malloc_tmp(v_printf);
	if (v_printf->conv & C)
		*(char *)tmp = (char)va_arg(v_printf->ap, int);
	else if (v_printf->conv & D)
		*(intmax_t *)tmp = (intmax_t)va_arg(v_printf->ap, intmax_t);
	else if (v_printf->conv & U)
		*(uintmax_t *)tmp = (uintmax_t)va_arg(v_printf->ap, uintmax_t);
	else if (v_printf->conv & F)
		*(float *)tmp = (float)va_arg(v_printf->ap, double);
	return (tmp);
}

unsigned	ft_i_size(t_printf *v_printf)
{
	int		char_bit;

	char_bit = CHAR_BIT;
	if (v_printf->conv & C)
		return (char_bit * sizeof(unsigned char));
	else if ((v_printf->conv & D || v_printf->conv & U) && v_printf->flags & H)
		return (char_bit * sizeof(short));
	else if ((v_printf->conv & D || v_printf->conv & U) &&
			(v_printf->flags & L || v_printf->flags & LL))
		return (char_bit * sizeof(long));
	else if (v_printf->conv & D || v_printf->conv & U)
		return (char_bit * sizeof(int));
	else if (v_printf->conv & F)
		return (char_bit * sizeof(float));
	return (0);
}

void		ft_bin(t_printf *v_printf)
{
	unsigned char	*res;
	unsigned		i;
	void			*tmp;

	res = NULL;
	tmp = NULL;
	i = ft_i_size(v_printf);
	if (!(tmp = ft_get_arg_b(v_printf)))
	{
		ft_buff(v_printf, "wrong format or invalid options", 31);
		return ;
	}
	res = (unsigned char *)tmp;
	while (--i + 1 > 0)
	{
		res[i / CHAR_BIT] & (1U << (i % CHAR_BIT)) ? ft_buff(v_printf, "1", 1) :
			ft_buff(v_printf, "0", 1);
		if (i % 8 == 0 && i != 0)
			ft_buff(v_printf, " ", 1);
	}
	ft_memdel(&res);
}
