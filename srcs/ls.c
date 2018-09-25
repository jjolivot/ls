/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 21:43:51 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 18:32:14 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_is_dir(char *path, t_flag *flag)
{
	struct stat	file;
	int			i;

	i = lstat(path, &file);
	if (i != -1)
		if (S_ISDIR(file.st_mode) || (S_ISLNK(file.st_mode) && flag->l == 0))
		{
			return (1);
		}
	return (0);
}

int	ft_rels(t_file *file, t_flag *flag, int multiple_arg)
{
	while (file)
	{
		if (ft_is_dir(file->path, flag))
			if (file->buf && S_ISDIR(file->buf->st_mode)
				&& ft_strcmp(file->name, ".")
				&& ft_strcmp(file->name, ".."))
			{
				ft_putchar('\n');
				ft_ls(file->path, flag, multiple_arg);
			}
		if (!ft_is_dir(file->path, flag) && file->buf &&
			(S_ISDIR(file->buf->st_mode) || (S_ISLNK(file->buf->st_mode) &&
			flag->l == 0)))
			g_error = 1;
		file = file->next;
	}
	return (0);
}

int	ft_putnbr_n(size_t i)
{
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putstr("\n");
	return (0);
}

int	ft_ls(char *path, t_flag *flag, int multiple_arg)
{
	t_file	*file;

	if (!ft_is_dir(path, flag))
		file = ft_info(0, 0, path, lstat);
	if (!ft_is_dir(path, flag))
		ft_display(file, flag);
	else
	{
		if (multiple_arg)
			ft_putstr(path);
		if (multiple_arg)
			ft_putstr(":\n");
		file = ft_info_link(path, lstat, flag);
		file = ft_sort_file(file, flag);
		if (flag->l && file && file->buf)
			ft_putnbr_n(file->total_size);
		ft_list_display(file, flag);
		if (multiple_arg)
			ft_putchar('\n');
		if (flag->rr)
			ft_rels(file, flag, 1);
	}
	ft_free_all_files(file);
	return (0);
}
