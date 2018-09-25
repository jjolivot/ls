/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:59:38 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/22 19:49:11 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_delete_arg(t_arg **arg)
{
	t_arg *tmp;

	tmp = (*arg);
	if ((*arg) && (*arg)->prev)
		*arg = (*arg)->prev;
	else if ((*arg) && (*arg)->next)
		*arg = (*arg)->next;
	else
		(*arg) = NULL;
	free(tmp->path);
	if (tmp && tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp && tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
}

int		ft_is_file(t_arg **maillon, t_flag *flag)
{
	struct stat	file;

	errno = 0;
	if ((*maillon) && (*maillon)->path)
		lstat((*maillon)->path, &file);
	if (S_ISDIR(file.st_mode) || (S_ISLNK(file.st_mode) && flag->l == 0))
	{
		return (0);
	}
	return (1);
}
