/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:14:37 by jjolivot          #+#    #+#             */
/*   Updated: 2017/11/23 19:14:51 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wc(char *str, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			wc++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (wc);
}