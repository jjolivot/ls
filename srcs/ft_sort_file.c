/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:11:17 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 21:02:11 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_inverse_file(struct s_file *maillon)
{
	struct s_file *tmp;

	if (maillon->prev)
		maillon->prev->next = (maillon)->next;
	if ((maillon)->next->next)
		maillon->next->next->prev = (maillon);
	(maillon)->next->prev = (maillon)->prev;
	(maillon)->prev = (maillon)->next;
	tmp = (maillon)->next->next;
	(maillon)->next->next = (maillon);
	(maillon)->next = tmp;
}

struct s_file	*ft_sort_time_file(struct s_file *file)
{
	while (file->next)
	{
		if (file->next && file->buf->st_mtimespec.tv_sec
				< file->next->buf->st_mtimespec.tv_sec)
		{
			ft_inverse_file(file);
			while (file->prev)
				file = file->prev;
		}
		else
			file = file->next;
	}
	while (file->prev)
		file = file->prev;
	return (file);
}

struct s_file	*ft_reverse_file(struct s_file *file)
{
	struct s_file *tmp;

	while (file->next)
	{
		tmp = file->prev;
		file->prev = file->next;
		file->next = tmp;
		file = file->prev;
	}
	tmp = file->prev;
	file->prev = file->next;
	file->next = tmp;
	return (file);
}

struct s_file	*ft_merge_time(struct s_file *maillon, struct s_file *second)
{
	t_file	*result;

	if (!maillon)
		return (second);
	if (!second)
		return (maillon);
	if (second && second->buf && second->buf->st_mtimespec.tv_sec <
			maillon->buf->st_mtimespec.tv_sec)
	{
		result = maillon;
		result->next = ft_merge_time(maillon->next, second);
		if (result->next)
			result->next->prev = result;
	}
	else
	{
		result = second;
		if (result)
			result->next = (ft_merge_time(maillon, second->next));
	}
	if (result->next)
		result->next->prev = result;
	result->prev = NULL;
	return (result);
}

struct s_file	*ft_merge_alpha(struct s_file *maillon, struct s_file *second)
{
	t_file	*result;

	if (!maillon)
		return (second);
	if (!second)
		return (maillon);
	if (ft_strcmp(maillon->path, second->path) < 0)
	{
		result = maillon;
		result->next = ft_merge_alpha(maillon->next, second);
		if (result->next)
			result->next->prev = result;
	}
	else
	{
		result = second;
		result->next = (ft_merge_alpha(maillon, second->next));
	}
	if (result->next)
		result->next->prev = result;
	result->prev = NULL;
	return (result);
}
