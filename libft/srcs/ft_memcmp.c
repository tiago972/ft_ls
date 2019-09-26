/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:20 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/11 20:27:27 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*cpys1;
	const char		*cpys2;
	unsigned char	c1;
	unsigned char	c2;

	cpys1 = (const char*)s1;
	cpys2 = (const char*)s2;
	c1 = 0;
	c2 = 0;
	while (n--)
	{
		c1 = *cpys1;
		c2 = *cpys2;
		if (c1 != c2)
			return (c1 - c2);
		cpys1++;
		cpys2++;
	}
	return (c1 - c2);
}
