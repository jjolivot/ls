/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:57:05 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 19:40:56 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t n)
{
	void	*tab;

	tab = (char *)malloc(sizeof(char) * n + 1);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, n + 1);
	return (tab);
}
