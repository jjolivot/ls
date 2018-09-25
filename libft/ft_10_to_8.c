/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:11:28 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 22:42:51 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_10_to_8(int start)
{
	int reste;
	int end;
	int i;

	end = 0;
	i = 1;
	reste = start;
	reste = start % 8;
	start = start / 8;
	end = reste;
	while (start != 0)
	{
		reste = start % 8;
		start = start / 8;
		end = reste * 10 * i + end;
		i = i * 10;
	}
	return (end);
}
