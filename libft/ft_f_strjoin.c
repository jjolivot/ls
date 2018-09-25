/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:55:55 by jjolivot          #+#    #+#             */
/*   Updated: 2018/01/29 23:57:22 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_f_strjoin(char *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
				ft_strlen((char *)s2)) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}
