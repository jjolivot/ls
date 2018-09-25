/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:20:46 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:03:18 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	int		ptr;
	int		neg;
	char	*nbrchar;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
		neg = 1;
	ptr = ft_digitnbr(n) + neg;
	nbrchar = (char *)malloc(sizeof(char) * ft_digitnbr(n) + neg + 1);
	if (nbrchar == NULL)
		return (NULL);
	if (n < 0)
	{
		nbrchar[0] = '-';
		n = -n;
	}
	nbrchar[ptr] = '\0';
	while (--ptr >= neg)
	{
		nbrchar[ptr] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
	}
	return (nbrchar);
}
