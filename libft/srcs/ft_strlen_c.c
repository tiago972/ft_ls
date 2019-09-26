/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:10:07 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 12:01:04 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlen_c(const char *str, char c)
{
	char *cpy;

	cpy = (char *)str;
	while (*cpy)
	{
		if (*cpy == c)
			return (cpy - str);
		cpy++;
	}
	return (-1);
}
