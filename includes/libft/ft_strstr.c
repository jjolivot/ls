/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:46:14 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/07 23:08:25 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	sizetofind;

	i = 0;
	j = 0;
	sizetofind = 0;
	while (to_find[sizetofind])
		sizetofind++;
	if (to_find[0] == '\0')
		return ((char *)&(str[0]));
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
		{
			if (sizetofind - 1 == j)
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
