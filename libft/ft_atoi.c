/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:23:05 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/07 23:14:03 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int negative;
	int content;

	negative = 1;
	content = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		negative = -1;
	if ((str[i] == '+') || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		content = content * 10 + ((int)str[i] - 48);
		i++;
	}
	return (negative * content);
}
