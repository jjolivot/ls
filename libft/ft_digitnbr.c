/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:06:25 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 19:34:39 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitnbr(int n)
{
	if (n / 10 == 0)
		return (1);
	return (ft_digitnbr(n / 10) + 1);
}
