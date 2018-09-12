/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:08:20 by jjolivot          #+#    #+#             */
/*   Updated: 2018/02/14 18:09:17 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_all_free(char **tab)
{
	int j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free(tab);
}
