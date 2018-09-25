/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:30:24 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:02:22 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*tab;

	tab = (void *)malloc(n);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, n);
	return (tab);
}
