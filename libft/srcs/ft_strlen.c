/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:10 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:51:11 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(char *str)
{
	char	*cpy;

	if (!str)
		return (0);
	cpy = str;
	while (*cpy)
		cpy++;
	return (cpy - str);
}
