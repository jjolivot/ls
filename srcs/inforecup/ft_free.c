/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:42:08 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 22:16:25 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_file	*ft_file_new(void)
{
	t_file *file;

	if (!(file = (t_file *)malloc(sizeof(struct s_file))))
		exit(0);
	file->prev = NULL;
	file->buf = NULL;
	file->path = NULL;
	file->name = NULL;
	file->next = NULL;
	return (file);
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

void	ft_free_file(t_file *file)
{
	if (file->path)
		free(file->path);
	if (file->buf)
		free(file->buf);
	if (file->name)
		free(file->name);
	file->name = NULL;
	file->buf = NULL;
	file->path = NULL;
	if (file && file->next)
		file->next->prev = NULL;
	if (file)
	{
		if (file->prev)
			file->prev->next = NULL;
		free(file);
	}
	file = NULL;
}

void	ft_free_all_files(t_file *file)
{
	if (file)
	{
		while (file->next)
		{
			if (file->prev)
			{
				ft_free_file(file->prev);
				file->prev = NULL;
			}
			file = file->next;
			if (file && file->prev)
			{
				ft_free_file(file->prev);
				file->prev = NULL;
			}
		}
		ft_free_file(file);
		file = NULL;
	}
}
