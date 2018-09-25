/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:03:27 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/22 20:25:16 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = ft_strlen((char *)src);
	while (i-- >= 0 || c == 0)
		if (src[i] == (char)c)
			return ((char *)(src + i));
	return (NULL);
}
