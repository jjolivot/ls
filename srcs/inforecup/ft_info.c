/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:53:40 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 22:18:32 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char	*ft_path_convert(char *path)
{
	int len;
	int i;

	len = ft_strlen(path);
	i = len;
	while (i-- > 0 && path[i] != '/')
		;
	return (ft_strdup((path + i + 1)));
}

void	ft_maxgrpusr(struct s_file *file)
{
	file->passwd = getpwuid(file->buf->st_uid);
	file->grp = getgrgid(file->buf->st_gid);
	if (file->grp)
		file->maxgrpsize = ft_strlen(file->grp->gr_name);
	else
		file->maxgrpsize = 0;
	if (file->passwd)
		file->maxusrsize = ft_strlen(file->passwd->pw_name);
}

t_file	*ft_info(t_file *prev, int mustlink, char *path,
		int (stati)(const char *, struct stat *))
{
	t_file		*file;
	struct stat	*buf;

	if (mustlink)
		file = ft_file_add(prev);
	else
		file = ft_file_new();
	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
		exit(0);
	if ((stati(path, buf)) != -1)
	{
		file->buf = buf;
		file->total_size = file->buf->st_blocks;
		ft_maxgrpusr(file);
	}
	else
		free(buf);
	file->next = NULL;
	if (file->prev)
		file->total_size = file->total_size + file->prev->total_size;
	file->path = ft_strdup(path);
	file->name = ft_path_convert(path);
	return (file);
}

t_file	*ft_info_2(char *path, struct dirent *dd,
		int (stati)(const char *, struct stat *), t_file *file)
{
	char *newpath;

	if (!(ft_strrchr(path, '/') && ft_strrchr(path, '/')[0] == '/'
		&& ft_strrchr(path, '/')[1] == '\0'))
	{
		newpath = ft_strjoin(path, "/");
		newpath = ft_f_strjoin(newpath, dd->d_name);
	}
	else
		newpath = ft_strjoin(path, dd->d_name);
	file = ft_info(file, 1, newpath, stati);
	free(newpath);
	return (file);
}

t_file	*ft_info_link(char *path,
		int (stati)(const char *, struct stat *), t_flag flag)
{
	t_file			*file;
	DIR				*dir;
	struct dirent	*dd;

	file = NULL;
	if ((dir = opendir(path)))
	{
		while ((dd = readdir(dir)))
			if (dd && (dd->d_name[0] != '.' || flag.a))
				file = ft_info_2(path, dd, stati, file);
		closedir(dir);
	}
	else
		ft_permission_denied(path);
	while (file && file->prev)
		file = file->prev;
	return (file);
}
