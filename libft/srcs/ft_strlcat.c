/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:50:57 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/02 14:06:09 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	*d;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	s = src;
	if (size <= i)
		return (size + j);
	d = dst + i;
	while (size - 1 > i && *s)
	{
		*d++ = *s++;
		size--;
	}
	*d = '\0';
	return (i + j);
}
