/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 21:43:51 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 18:48:25 by jjolivot         ###   ########.fr       */
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


int	ft_rels(t_file *file, t_flag flag, int multiple_arg)
{
	while(file)
	{
		if (file->buf && S_ISDIR(file->buf->st_mode) && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
		{
			if (!ft_strstr(file->path, "dev/fd/") && !ft_strstr(file->path, "dev//fd/") )
			{
				ft_putchar('\n');
				ft_ls(file->path, flag, multiple_arg);
			}
			else
			{
				ft_putstr("ft_ls: ");
				ft_putstr(ft_strrchr(file->path, '/') + 1);
				ft_putstr(": directory causes a cycle\n");
			}
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
	//	ft_free_file(file);
	}
	else
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
		file = ft_sort_file(file, flag);
		if (flag.l && file && file->buf)
		{
			ft_putstr("total ");//display le total
			ft_putnbr(file->total_size);
			ft_putstr("\n");
		}
		ft_list_display(file, flag);
		if (multiple_arg)
			ft_putchar('\n');
/*		while (file->next)
			file = file->next;
		while(file->prev)
		{
			printf("%s\n", file->path);
			file = file->prev;
		}
			printf("%s\n", file->path);
*/	//				display
	//si -R, pour chaque dossier dans la liste relancer ls
		if (flag.R)
			ft_rels(file, flag, 1);
	}
	ft_free_all_files(file);
	return (0);
}
