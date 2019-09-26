/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:28:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/07 09:08:41 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_inifunptr(t_funptr funptr[14])
{
	funptr[0].conv |= C;
	funptr[0].f = &ft_pad_c;
	funptr[1].conv |= S;
	funptr[1].f = &ft_pad_s;
	funptr[2].conv |= D;
	funptr[2].f = &ft_pad_i;
	funptr[3].conv |= I;
	funptr[3].f = &ft_pad_i;
	funptr[4].conv |= O;
	funptr[4].f = &ft_pad_u;
	funptr[5].conv |= U;
	funptr[5].f = &ft_pad_u;
	funptr[6].conv |= X;
	funptr[6].f = &ft_pad_u;
	funptr[7].conv |= XX;
	funptr[7].f = &ft_pad_u;
	funptr[8].conv |= P;
	funptr[8].f = &ft_pad_p;
	funptr[9].conv |= J;
	funptr[9].f = &ft_dispatch_jz;
	funptr[10].conv |= Z;
	funptr[10].f = &ft_dispatch_jz;
	ft_inifunptr2(funptr);
}

void			ft_inifunptr2(t_funptr funptr[14])
{
	funptr[11].conv |= POURCENT;
	funptr[11].f = &ft_pad_c;
	funptr[12].conv |= UU;
	funptr[12].f = &ft_pad_u;
	funptr[13].conv |= F;
	funptr[13].f = &ft_handle_f;
}

uintmax_t		ft_log_dispatch(t_printf *v_printf, uintmax_t uintarg)
{
	if (v_printf->conv & X || v_printf->conv & XX)
		return (ft_log(uintarg, 16));
	else if (v_printf->conv & U || v_printf->conv & Z || v_printf->conv & UU)
		return (ft_log(uintarg, 10));
	else if (v_printf->conv & O)
		return (ft_log(uintarg, 8));
	return (0);
}

void			ft_dispatch_jz(t_printf *v_printf)
{
	if (*(v_printf->str) == 'u' && v_printf->str++ && (v_printf->conv |= U))
		ft_pad_u(v_printf);
	else if (*(v_printf->str) == 'x' &&
			v_printf->str++ && (v_printf->conv |= X))
		ft_pad_u(v_printf);
	else if (*(v_printf->str) == 'd' &&
			v_printf->str++ && (v_printf->conv |= D))
		ft_pad_i(v_printf);
	else if (*(v_printf->str) == 'i' &&
			v_printf->str++ && (v_printf->conv |= D))
		ft_pad_i(v_printf);
}
