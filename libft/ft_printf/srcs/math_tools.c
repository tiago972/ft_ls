/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:30:14 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/05 12:40:01 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>
uintmax_t		ft_log(uintmax_t nb, uintmax_t base)
{
	uintmax_t	power;

	power = 0;
	while (nb >= base)
	{
		nb /= base;
		power++;
	}
	power++;
	return (power);
}

int				ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int				ft_max(int a, int b)
{
	return (a > b ? a : b);
}

uintmax_t		ft_abs(intmax_t a)
{
	return (a < 0 ? -a : a);
}

intmax_t		ft_iterative_power(intmax_t nb, int power)
{
	intmax_t	res;

	res = 1;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		if (res > LLONG_MAX / nb)
			return (-1);
		res = res * nb;
		power--;
	}
	return (res);
}
