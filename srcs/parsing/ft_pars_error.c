/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:46:07 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 17:59:56 by jjolivot         ###   ########.fr       */
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
			flag->rr = 1;
		if (c == 'r')
			flag->r = 1;
		if (c == 'a')
			flag->a = 1;
		return (0);
	}
	return (1);
}

void	ft_permission_denied(char *path)
{
	struct stat	buf;
	char		*tmp;
	int			s;

	s = stat(path, &buf);
	if (s != -1)
	{
		tmp = ft_path_convert(path);
		ft_putstr("ft_ls: ");
		ft_putstr(tmp);
		free(tmp);
		ft_putstr(": Permission denied\n");
		g_error = 1;
	}
	else
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
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
	struct stat		buf;
	struct s_arg	*tmp;
	struct s_arg	*first;

	first = (*maillon);
	while ((*maillon))
	{
		if (lstat((*maillon)->path, &buf) == -1)
		{
			ft_putstr("ft_ls: ");
			ft_putstr((*maillon)->path);
			ft_putstr(": No such file or directory\n");
			g_error = 1;
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
	if (!(*maillon))
		exit(1);
}

int		ft_pars_error(int argc, char **argv, t_flag *flag)
{
	int i;
	int y;

	i = 1;
	y = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] && argv[i][1] != '-')
	{
		while (argv[i][++y])
			if (ft_is_arg(argv[i][y], flag))
				return (ft_bad_arg_error(argv[i][y]));
		i++;
		y = 0;
	}
	while (i < argc && argv[i])
	{
		if (!ft_strlen(argv[i]))
			return (ft_empty_arg_error());
		i++;
	}
	return (0);
}
