/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:47:05 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/07 23:09:40 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;
	int		sizetofind;

	i = 0;
	j = 0;
	sizetofind = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (sizetofind - 1 == j)
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
