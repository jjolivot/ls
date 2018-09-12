/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:59:38 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/09 16:20:20 by jjolivot         ###   ########.fr       */
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

int		ft_is_file(t_arg **maillon, t_flag flag)
{
	//si n'existe pas, supprime le maillon et renvoie 0
	struct	stat file;

	errno = 0;
	if(lstat((*maillon)->path, &file) && errno == ENOENT)
	{
		ft_putstr("ft_ls: ");
		ft_putstr((*maillon)->path);
		ft_putstr(": No such file or directory\n");
	//	ft_arg_print(*maillon);
		ft_delete_arg(maillon);
	//	ft_arg_print(*maillon);
		return (0);
	}
	//si dossier ou link sans -l renvoi 0
	if (S_ISDIR(file.st_mode) || (S_ISLNK(file.st_mode) && flag.l == 0))
	{
		return (0);
	}//sinon renvoie 1
	return(1);
}
