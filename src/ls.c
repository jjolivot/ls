/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 21:43:51 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/12 14:42:37 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_is_dir(char *path, t_flag flag)
{
	struct stat file;

	lstat(path, &file);
	if (S_ISDIR(file.st_mode) || (S_ISLNK(file.st_mode) && flag.l == 0))
	{
		return (1);
	}
	return(0);
}

void	ft_print_file(t_file *file)
{
	while(file)
	{
		printf("name %s    size %i     totalsize %i\n", file->path, (int)file->buf->st_size, (int)file->total_size);
		ft_putchar('\n');
		file = file->next;
	}
}

int	ft_rels(t_file *file, t_flag flag, int multiple_arg)
{
	while(file)
	{
		if (S_ISDIR(file->buf->st_mode))
		{
			ft_putchar('\n');
				ft_ls(file->path, flag, multiple_arg);
		}
		file = file->next;
	}
	return(0);
}

int	ft_ls(char *path, t_flag flag, int multiple_arg)
{
	t_file	*file;
	//Verifier si fichier ou dossier
	//			si fichiers (sauf si link (non supprime) et -l)
	if (!ft_is_dir(path, flag))
	{
	//					prendre les infos dans maillon unique (lstat)
		file = ft_info(0, 0, path, lstat);
		ft_display(file, flag);
		ft_free_file(file);
	}
	if (ft_is_dir(path, flag))
	{
	//			si dossier et multiple_arg:print le titre
		if (multiple_arg)
				ft_putstr(path);
		if (multiple_arg)
			ft_putstr(":\n");
	//			si dossier ou link sans -l
	//				prendre les infos dans liste chaine (stat)
		file = ft_info_link(path, lstat, flag);
	//				sort les fichiers
	//		file = sort(file)
		if (flag.l && file)
		{
			ft_putstr("total ");//display le total
			ft_putnbr(file->total_size);
			ft_putstr("\n");
		}
		ft_list_display(file, flag);
	//				display
	//si -R, pour chaque dossier dans la liste relancer ls
		if (flag.R)
			ft_rels(file, flag, 1);
		ft_free_all_files(file);
	}
	return (0);
}
