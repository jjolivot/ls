/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:45:14 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 17:58:57 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int		ft_bad_arg_error(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\n usage: ls [-laRrt] [file ...]\n");
	g_error = 1;
	return (1);
}

int		ft_empty_arg_error(void)
{
	ft_putstr("ft_ls: fts_open: No such file or directory\n");
	g_error = 1;
	return (1);
}
