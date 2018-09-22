/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:02:56 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 22:38:13 by jjolivot         ###   ########.fr       */
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
	flag->rr = 0;
	flag->a = 0;
}

void	ft_free_all_arg(t_arg *arg)
{
	t_arg	*tmp;

	if (arg->prev)
		while (arg)
		{
			tmp = arg;
			arg = arg->next;
			free(tmp->path);
			free(tmp);
		}
}

int		main(int argc, char **argv)
{
	t_flag	flag;
	t_arg	*arg;
	t_arg	*first;
	int		multiple_arg;

	arg = NULL;
	multiple_arg = 0;
	ft_set_zero(arg, &flag);
	if (ft_parsing(argc, argv, &arg, &flag))
		return (-1);
	if (arg->next)
		multiple_arg = 1;
	first = arg;
	while (arg)
	{
		ft_ls(arg->path, flag, multiple_arg);
		arg = arg->next;
	}
	ft_free_all_arg(first);
	return (0);
}
