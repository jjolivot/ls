/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:46:07 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/12 15:59:14 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int	ft_is_arg(char c, t_flag *flag)
{
	if (c == 't' || c == 'l' || c == 'r' || c == 'R' || c == 'a')
	{
		if (c == 't')
			flag->t = 1;
		if (c == 'l')
			flag->l = 1;
		if (c == 'R')
			flag->R = 1;
		if (c == 'r')
			flag->r = 1;
		if (c == 'a')
			flag->a = 1;
		return(0);
	}
	return (1);
}

void	ft_permission_denied(char *path)
{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": Permission denied\n");

}

int ft_bad_arg_error(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\n usage: ls [-laRrt] [file ...]\n");
	return (1);
}

int	ft_empty_arg_error()
{
	ft_putstr("ls: fts_open: No such file or directory\n");
	return (1);
}


// retourne -1 si erreur, et ft_ls quitte.
int	ft_pars_error(int argc, char **argv, t_flag *flag)
{
	int i;
	int y;

	i = 1;
	y = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != '-')
	{
		while (argv[i][++y])
			if (ft_is_arg(argv[i][y], flag))
				return (ft_bad_arg_error(argv[i][y]));
		i++;
		y = 0;
	}
	while(i < argc && argv[i])
	{
		if(!ft_strlen(argv[i]))
			return(ft_empty_arg_error());
		i++;
		// si le dossier ou fichier n'existe pas, print
	}
	return (0);
}

