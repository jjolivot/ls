/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:28:17 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 17:52:44 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	int	j;
	int	k;

	j = 0;
	while (tab[j])
	{
		k = 0;
		while (tab[j][k])
		{
			ft_putchar(tab[j][k]);
			k++;
		}
		if (tab[j])
			ft_putchar('\n');
		j++;
	}
}
