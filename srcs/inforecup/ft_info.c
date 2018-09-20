/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:53:40 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 18:53:58 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_file	*ft_file_new(void)
{
	t_file *file;

	if(!(file = (t_file *)malloc(sizeof(struct s_file))))
			exit(0);
	file->prev = NULL;
	file->buf = NULL;
	file->path = NULL;
	file->name = NULL;
	file->next = NULL;
	return(file);
}

t_file	*ft_file_add(t_file *file)
{
	t_file *new;

	new = ft_file_new();
	if (file)
		file->next = new;
	new->prev = file;
	new->next = NULL;
	return (new);
}

char	*ft_path_convert(char *path)
{
	int len;
	int i;

	len = ft_strlen(path);
	i = len;
	while(i-- > 0 && path[i] != '/')
		;
	return(ft_strdup((path + i + 1)));
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

t_file	*ft_info(t_file *prev, int mustlink, char *path, int (stati)(const char *, struct stat *))
{
	t_file		*file;
	struct stat	*buf;

	buf = 0;
	if (mustlink)
		file = ft_file_add(prev);
	else
		file = ft_file_new();
	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
		exit (0);
	if ((stati(path, buf)) != -1)
	{
		file->buf = buf;
		file->total_size = file->buf->st_blocks;
		ft_maxgrpusr(file);
	}
	else
	{
		if (buf)
			free(buf);
		file->buf = NULL;
		file->total_size = 0;
	}
	file->next = NULL;
	if (file->prev)
		file->total_size = file->total_size + file->prev->total_size;
	file->path = ft_strdup(path);
	file->name = ft_path_convert(path);
	return (file);
}

t_file	*ft_info_link(char *path, int  (stati)(const char *, struct stat *), t_flag flag)
{
	t_file	*file;
	DIR	*dir;
	struct dirent *dd;
	char *newpath;

	file = NULL;
	if ((dir = opendir(path)))
	{
		while ((dd = readdir(dir)))
		{
			if (dd && (dd->d_name[0] != '.' || flag.a))
			{
				if (!(ft_strrchr(path, '/') && ft_strrchr(path, '/')[0] == '/' && ft_strrchr(path, '/')[1] == '\0'))
				{
					newpath = ft_strjoin(path, "/");
					newpath = ft_f_strjoin(newpath, dd->d_name);
				}
				else
					newpath = ft_strjoin(path, dd->d_name);
				file = ft_info(file, 1, newpath, stati);
				free(newpath);
			}
		}
	//	while(file)
	//	{
	//		printf("file adresse %p  \n   file path %s\n", file, file->path);
	//		file = file->prev;
	//	}
		closedir(dir);
	}
	else
		ft_permission_denied(path);
	while (file && file->prev)
		file = file->prev;
	return (file);
}
