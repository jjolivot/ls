/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:13:47 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/07 22:54:48 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char static	*ft_strcpyz(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpyz(dest, src);
	return (dest);
}
