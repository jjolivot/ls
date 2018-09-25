/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:04:53 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/24 22:34:14 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_print_date_tab(time_t tv_sec)
{
	time_t	t;
	char	*tmp;

	t = time(0);
	ft_putstr((tmp = ft_strsub(ctime(&tv_sec), 4, 7)));
	free(tmp);
	if (tv_sec - t < 0 && tv_sec - t > -(365.25 * 24 * 60 * 30))
		ft_putstr((tmp = ft_strsub(ctime(&tv_sec), 11, 5)));
	else
		ft_putstr((tmp = ft_strsub(ctime(&tv_sec), 19, 5)));
	free(tmp);
	ft_putstr("\t");
}

void	ft_list_display(t_file *file, t_flag *flag)
{
	while (file)
	{
		ft_display(file, flag);
		file = file->next;
	}
}

void	ft_grp_usr_padding(struct s_file *file)
{
	int				space_number;

	file->passwd = getpwuid(file->buf->st_uid);
	file->grp = getgrgid(file->buf->st_gid);
	if (file->passwd && file->passwd->pw_name)
	{
		ft_putstr(file->passwd->pw_name);
		space_number = file->maxusrsize - ft_strlen(file->passwd->pw_name);
		while (space_number--)
			ft_putchar(' ');
	}
	else
		ft_putnbr(file->buf->st_uid);
	ft_putstr("\t");
	if (!(file->grp))
		ft_putnbr(file->buf->st_gid);
	else
	{
		ft_putstr(file->grp->gr_name);
		space_number = file->maxgrpsize - ft_strlen(file->grp->gr_name);
		while (space_number--)
			ft_putchar(' ');
	}
	ft_putstr("\t");
}

void	ft_display2(t_file *file)
{
	char			*tmp;

	ft_putstr((tmp = ft_file_and_permissions(file->buf->st_mode)));
	free(tmp);
	ft_putstr("\t");
	ft_putnbr(file->buf->st_nlink);
	ft_putstr("\t");
	ft_grp_usr_padding(file);
	if (S_ISCHR(file->buf->st_mode) || S_ISBLK(file->buf->st_mode))
	{
		ft_putnbr(major(file->buf->st_rdev));
		ft_putstr(",\t");
		ft_putnbr(minor(file->buf->st_rdev));
	}
	else
		ft_putnbr(file->buf->st_size);
	ft_putstr("\t");
	ft_print_date_tab(file->buf->st_mtimespec.tv_sec);
}

int		ft_display(t_file *file, t_flag *flag)
{
	char			*tmp;

	if (flag->l && file->buf)
	{
		ft_display2(file);
	}
	if (file->buf)
		ft_putstr(file->name);
	if (file->buf && flag->l && S_ISLNK(file->buf->st_mode))
	{
		ft_putstr(" -> ");
		if (!(tmp = (char *)malloc(sizeof(char) * 4096 + 1)))
			exit(0);
		tmp[readlink(file->path, tmp, 4096)] = '\0';
		ft_putstr(tmp);
		free(tmp);
	}
	if (file->buf)
		ft_putstr("\n");
	return (0);
}
