/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:46:07 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/13 16:05:14 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int		ft_is_arg(char c, t_flag *flag)
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
	struct	stat buf;
	int		s;
	s = stat(path, &buf);
	if (s != -1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": Permission denied\n");
	}
	else
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
}

int		ft_bad_arg_error(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\n usage: ls [-laRrt] [file ...]\n");
	return (1);
}

int		ft_empty_arg_error()
{
	ft_putstr("ls: fts_open: No such file or directory\n");
	return (1);
}

void	ft_arg_del(struct s_arg *maillon)
{
	struct s_arg *tmp;

	tmp = maillon;

	if (maillon->prev)
		maillon->prev->next = maillon->next;
	if (maillon->next)
		maillon->next->prev = maillon->prev;
	free(maillon->path);
	free(maillon);
}

void	ft_check_fexist(struct s_arg **maillon)
{
	struct stat buf;
	struct s_arg *tmp;
	struct s_arg *first;

	first = (*maillon);
	while ((*maillon))
	{
		if (lstat((*maillon)->path, &buf) == -1)
		{
			ft_putstr("ls: ");
			ft_putstr((*maillon)->path);
			ft_putstr(": No such file or directory\n");
			tmp = (*maillon);
			(*maillon) = (*maillon)->next;
			if (first == tmp)
				first = first->next;
			ft_arg_del(tmp);
		}
		else
			(*maillon) = (*maillon)->next;
	}
	(*maillon) = first;
//	while((*maillon) && (*maillon)->prev)
//		*maillon = (*maillon)->prev;
	if (!(*maillon))
		exit(1);
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

