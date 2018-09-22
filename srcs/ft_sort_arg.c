/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:39:17 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 21:08:39 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_is_dir_and_file(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

void			ft_inverse_maillon(struct s_arg **maillon)
{
	struct s_arg *tmp;

	if ((*maillon)->prev)
		(*maillon)->prev->next = (*maillon)->next;
	if ((*maillon)->next->next)
		(*maillon)->next->next->prev = (*maillon);
	(*maillon)->next->prev = (*maillon)->prev;
	(*maillon)->prev = (*maillon)->next;
	tmp = (*maillon)->next->next;
	(*maillon)->next->next = (*maillon);
	(*maillon)->next = tmp;
}

struct s_arg	*ft_time_sort(struct s_arg **maillon, t_flag flag)
{
	struct stat file;
	struct stat filenext;

	while ((*maillon)->next)
	{
		if (flag.l)
			lstat((*maillon)->path, &file);
		if ((*maillon)->next && flag.l)
			lstat((*maillon)->next->path, &filenext);
		if (!flag.l)
			stat((*maillon)->path, &file);
		if ((*maillon)->next && !flag.l)
			stat((*maillon)->next->path, &filenext);
		if (file.st_mtimespec.tv_sec < filenext.st_mtimespec.tv_sec)
		{
			ft_inverse_maillon(maillon);
			while ((*maillon)->prev)
				*maillon = (*maillon)->prev;
		}
		else
			*maillon = (*maillon)->next;
	}
	while ((*maillon)->prev)
		*maillon = (*maillon)->prev;
	return (*maillon);
}

struct s_arg	*ft_sort_file_and_dir(struct s_arg **maillon, t_flag flag)
{
	struct s_arg *first;

	first = (*maillon);
	while ((*maillon)->next)
	{
		ft_check_fexist(maillon);
		if (ft_is_dir_and_file(ft_is_file(maillon, flag),
					ft_is_file(&(*maillon)->next, flag)))
		{
			ft_inverse_maillon(maillon);
			while (first->prev)
				first = first->prev;
			*maillon = first;
		}
		else
		{
			if ((*maillon) && (*maillon)->next)
				*maillon = (*maillon)->next;
		}
	}
	while ((*maillon)->prev)
		*maillon = (*maillon)->prev;
	return (*maillon);
}

struct s_arg	*ft_sort(struct s_arg **maillon)
{
	struct s_arg *first;

	first = (*maillon);
	while ((*maillon)->next)
	{
		if (ft_strcmp((*maillon)->path, (*maillon)->next->path) > 0)
		{
			ft_inverse_maillon(maillon);
			while (first->prev)
				first = first->prev;
			*maillon = first;
		}
		else
			*maillon = (*maillon)->next;
	}
	*maillon = first;
	return (*maillon);
}
