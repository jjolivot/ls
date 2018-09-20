/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:11:17 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/18 18:36:47 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_inverse_file(struct s_file *maillon)
{
	struct s_file *tmp;

	if (maillon->prev)
		maillon->prev->next = (maillon)->next;
	if((maillon)->next->next)
		maillon->next->next->prev = (maillon);
	(maillon)->next->prev = (maillon)->prev;
	(maillon)->prev = (maillon)->next;
	tmp = (maillon)->next->next;
	(maillon)->next->next = (maillon);
	(maillon)->next = tmp;
}

struct s_file *ft_sort_time_file(struct s_file *file)
{
	while(file->next)
	{
		if (file->next && file->buf->st_mtimespec.tv_sec < file->next->buf->st_mtimespec.tv_sec)
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
	return(file);
}

struct s_file	*ft_reverse_file(struct s_file *file)
{
	struct s_file *tmp;

	while(file->next)
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
/*
struct s_file *ft_sort_alpha_file(struct s_file *maillon)
{
		struct s_file *first;

	first = maillon;
		while (maillon->next)
	{
			printf("%s\n", maillon->path);
			if (ft_strcmp((maillon)->path, (maillon)->next->path) > 0)
			{
				ft_inverse_file(maillon);
				while (first->prev)
					first = first->prev;
				maillon = first;
			}
			else
				maillon = maillon->next;
		}
	maillon = first;
	return (maillon);
}

struct s_file *ft_merge(struct s_file *maillon, struct s_file *second)
{
	if (!maillon)
		return(second);
	if (!second)
		return(maillon);
	if (ft_strcmp(maillon->path, second->path) > 0)
	{
		maillon->next = ft_merge(maillon->next, second);
		maillon->next->prev = maillon;
		maillon->prev = NULL;
		return (maillon);
	}
	else
	{
		second->next = ft_merge(maillon, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}
*/
struct s_file *ft_merge_time(struct s_file *maillon, struct s_file *second)
{
	t_file	*result;

	if (!maillon)
		return(second);
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
	return(result);
}

struct s_file *ft_merge_alpha(struct s_file *maillon, struct s_file *second)
{
	t_file	*result;

	if (!maillon)
		return(second);
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
	return(result);
}

struct s_file *ft_split(struct s_file *maillon)
{
	struct s_file	*slow;
	struct s_file	*fast;

	fast = maillon;
	slow = maillon;
	if (!maillon || maillon->next == 0)
		return (maillon);
	while(fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return(slow);
}

struct s_file *ft_merge_sort_file(struct s_file *maillon, struct s_file *(ft_merge)(struct s_file *maillon, struct s_file *second))
{
	struct s_file	*second;

	if (!maillon || maillon->next == 0)
		return(maillon);
	second = ft_split(maillon);
	if (second && second->prev)
		second->prev->next = NULL;
	maillon = ft_merge_sort_file(maillon, ft_merge);
	second = ft_merge_sort_file(second, ft_merge);
	maillon = ft_merge(maillon, second);
	return(maillon);
}

struct s_file *ft_total_size(struct s_file *file)
{
	size_t	ts;
	int		grp;
	int		usr;
	struct s_file	*first;

	first = file;
	ts = 0;
	grp = 0;
	usr = 0;
	while (file && file->next)
	{
		ts = (ts < file->total_size ? file->total_size : ts);
		grp = (grp < file->maxgrpsize ? file->maxgrpsize : grp);
		usr = (usr < file->maxusrsize ? file->maxusrsize : usr);
		file = file->next;
	}

	ts = (ts < file->total_size ? file->total_size : ts);
	grp = (grp < file->maxgrpsize ? file->maxgrpsize : grp);
	usr = (usr < file->maxusrsize ? file->maxusrsize : usr);
	while (file && file)
	{
		file->total_size = ts;
		file->maxgrpsize = grp;
		file->maxusrsize = usr;
		file = file->prev;
	}
	return (first);
}

struct s_file *ft_sort_file(struct s_file *file, t_flag flag)
{
	if (file)
	{
		ft_total_size(file);
		file = ft_merge_sort_file(file, ft_merge_alpha);
		if (flag.t)
		file = ft_merge_sort_file(file, ft_merge_time);
		if (flag.r)
			file = ft_reverse_file(file);
	}
	return (file);
}


