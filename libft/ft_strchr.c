/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:52:56 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 19:39:02 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;
	int	y;

	i = 0;
	y = ft_strlen(src);
	if (c == 0)
		return ((char *)(src + y));
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)(src + i));
		i++;
	}
	return (NULL);
}
