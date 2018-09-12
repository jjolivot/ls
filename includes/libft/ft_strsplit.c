/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:26 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:41:39 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		b;

	if (!s || !(p = (char **)malloc(8 * (ft_wc((char *)s, c) + 1))))
		return (NULL);
	b = -1;
	i = 0;
	while (++b < (int)ft_strlen(s))
	{
		j = -1;
		if ((b != 0 && s[b - 1] == c && s[b] != c) || (b == 0 && s[b] != c))
		{
			p[i] = (char *)malloc(sizeof(char) * (ft_wl((char *)s, b, c) + 1));
			if (p[i] == NULL)
				return (NULL);
			while (s[b + ++j] != c && s[b + j])
				p[i][j] = s[b + j];
			p[i++][j] = '\0';
			b = b + j;
		}
	}
	p[i] = NULL;
	return (p);
}
