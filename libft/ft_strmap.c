/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:37:56 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 19:50:07 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!new)
		return (0);
	new[ft_strlen((char *)s) + 1] = '\0';
	i = -1;
	while (s[++i])
		new[i] = f(s[i]);
	new[i] = '\0';
	return (new);
}
