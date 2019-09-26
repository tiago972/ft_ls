/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:39:59 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/06 15:46:12 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../includes/libft.h"

char	*ft_pad_s2(int *tmp, char *str_arg, t_printf *v_printf, int *len)
{
	if (!str_arg)
	{
		if (!(str_arg = ft_strnew(6)))
			return (0);
		ft_memmove(str_arg, "(null)", 6);
		*tmp = 1;
	}
	if (v_printf->flags & DOT)
	{
		if (v_printf->prec < 0 && (v_printf->flags & STAR))
			v_printf->prec = ft_strlen(str_arg);
		else if (v_printf->prec == -2)
			v_printf->prec = 0;
		*len = ft_min(v_printf->prec, ft_strlen(str_arg));
	}
	else
		*len = ft_strlen(str_arg);
	return (str_arg);
}
