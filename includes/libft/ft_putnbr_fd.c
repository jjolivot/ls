/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:55:04 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 16:54:39 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if ((-2147483648 < nb) || (nb >= 2147483647))
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = nb * -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			nb = nb % 10;
			ft_putchar_fd(nb + '0', fd);
		}
		else
			ft_putchar_fd(nb + '0', fd);
	}
}
