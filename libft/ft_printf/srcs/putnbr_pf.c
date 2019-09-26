/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:53:29 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/06 15:31:55 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../..//includes/libft.h"

void		ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
			uintmax_t power)
{
	uintmax_t size_b;

	size_b = ft_strlen(base);
	(void)power;
	if (nb >= size_b)
		ft_putnbr_pf_u(v_printf, nb / size_b, base, power);
	ft_buff(v_printf, &base[nb % size_b], 1);
}

void		ft_putnbr_pf(t_printf *v_printf, intmax_t nb, uintmax_t power)
{
	uintmax_t	power_cpy;
	uintmax_t	nb_cpy;
	static char	base[11] = "0123456789";

	while (power > 0)
	{
		power_cpy = power;
		nb_cpy = nb;
		while (--power_cpy > 0)
			nb_cpy /= 10;
		ft_buff(v_printf, &base[nb_cpy % 10], 1);
		power--;
	}
}
