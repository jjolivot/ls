/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:01:36 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:49:42 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	int			j;

	j = 0;
	i = ft_strlen(dest);
	if (i >= n)
		return (n + ft_strlen(src));
	while (src[j] && j < (int)((int)n - i - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (!(src[j]) && !(n > i))
	{
		dest[i + j] = '\0';
		return (ft_strlen(dest));
	}
	if (n > i)
	{
		dest[i + j] = '\0';
		return (i + ft_strlen(src));
	}
	if (ft_strlen(dest) < ft_strlen(src))
		return (ft_strlen(src));
	return (ft_strlen(src) + ft_strlen(dest));
}
