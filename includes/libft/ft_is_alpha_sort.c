/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alpha_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:01:45 by jjolivot          #+#    #+#             */
/*   Updated: 2018/07/28 20:57:24 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//renvoie 0 si le premier arg vient avant le second, 1 sinon.

int ft_is_alpha_sort(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] <= b[i] && a[i] && b[i])
		i++;
	
	if (a[i] > b[i])
		return (1);
	return (0);
}
