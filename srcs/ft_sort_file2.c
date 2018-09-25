/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:06:18 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/24 22:36:34 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_file	*ft_split(struct s_file *maillon)
{
	struct s_file	*slow;
	struct s_file	*fast;

	fast = maillon;
	slow = maillon;
	if (!maillon || maillon->next == 0)
		return (maillon);
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return (slow);
}

struct s_file	*ft_merge_sort_file(struct s_file *maillon,
	struct s_file *(ft_merge)(struct s_file *maillon, struct s_file *second))
{
	struct s_file	*second;

	if (!maillon || maillon->next == 0)
		return (maillon);
	second = ft_split(maillon);
	if (second && second->prev)
		second->prev->next = NULL;
	maillon = ft_merge_sort_file(maillon, ft_merge);
	second = ft_merge_sort_file(second, ft_merge);
	maillon = ft_merge(maillon, second);
	return (maillon);
}

void			ft_total_size_plus(size_t *ts, int *grp, int *usr,
		struct s_file *file)
{
	*ts = (*ts < file->total_size ? file->total_size : *ts);
	*grp = (*grp < file->maxgrpsize ? file->maxgrpsize : *grp);
	*usr = (*usr < file->maxusrsize ? file->maxusrsize : *usr);
}

struct s_file	*ft_total_size(struct s_file *file)
{
	size_t			ts;
	int				grp;
	int				usr;
	struct s_file	*first;

	first = file;
	ts = 0;
	grp = 0;
	usr = 0;
	while (file && file->next)
	{
		ft_total_size_plus(&ts, &grp, &usr, file);
		file = file->next;
	}
	ft_total_size_plus(&ts, &grp, &usr, file);
	while (file)
	{
		file->total_size = ts;
		file->maxgrpsize = grp;
		file->maxusrsize = usr;
		file = file->prev;
	}
	return (first);
}

struct s_file	*ft_sort_file(struct s_file *file, t_flag *flag)
{
	if (file)
	{
		ft_total_size(file);
		file = ft_merge_sort_file(file, ft_merge_alpha);
		if (flag->t)
			file = ft_merge_sort_file(file, ft_merge_time_nf);
		if (flag->r)
			file = ft_reverse_file(file);
	}
	return (file);
}
