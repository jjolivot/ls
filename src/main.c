/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:02:56 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/12 15:47:52 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_set_zero(t_arg *arg, t_flag *flag)
{
	arg = NULL;
	flag = (struct s_flag *)malloc(sizeof(t_flag));
	flag->t = 0;
	flag->r = 0;
	flag->l = 0;
	flag->R = 0;
	flag->a = 0;
}
int main(int argc, char **argv)
{
	t_flag	flag;
	t_arg	*arg;
	int		multiple_arg;

	arg = 0;
	multiple_arg = 0;
	ft_set_zero(arg, &flag);
	if (ft_parsing(argc, argv, &arg, &flag)) //print et quitte erreurs de flags, arg vide ou inexistant.
											//Met une liste chaine d'argument dans arg.
		return (-1);
	if (arg->next)
		multiple_arg = 1;
	while (arg)
	{
		ft_ls(arg->path, flag, multiple_arg);
		arg = arg->next;
	}
	return (0);
	//trie les fichiers
	//verifie tout les fichiers existent
	//place les 
}
