/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:47:01 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:48:15 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memrcpy(void *dst, const void *src, size_t n)
{
	while (n-- > 0)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_memrcpy(dst, src, len);
	return (dst);
}
