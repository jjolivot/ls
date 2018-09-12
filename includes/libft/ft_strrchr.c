/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:03:27 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/07 22:03:18 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = ft_strlen((char *)src) + 1;
	while (i-- != -1 || c == 0)
		if (src[i] == (char)c)
			return ((char *)(src + i));
	return (NULL);
}
