/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:28:21 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 19:47:25 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		p;
	int		e;
	int		n;
	int		i;
	char	*tab;

	if (!s)
		return (NULL);
	e = 0;
	p = 0;
	while (s[p] == ' ' || s[p] == '\n' || s[p] == '\t')
		p++;
	if (!(s[p]))
		return (ft_strdup(""));
	n = ft_strlen((char *)s);
	while (s[n - e - 1] == ' ' || s[n - e - 1] == '\n' || s[n - e - 1] == '\t')
		e++;
	tab = (char *)malloc(sizeof(char) * (n - p - e) + 1);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (++i + p + e < n)
		tab[i] = s[p + i];
	tab[i] = '\0';
	return (tab);
}
