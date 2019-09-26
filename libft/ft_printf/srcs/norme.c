/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:07:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/15 16:10:23 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_begin(t_printf *v_printf, char *str, t_funptr funptr[14])
{
	ft_memset(v_printf, 0, sizeof(t_printf));
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	ft_inifunptr(funptr);
	v_printf->prec = -2;
	v_printf->str = (char *)str;
}
