/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:02:56 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 18:53:19 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flag	*ft_set_zero(t_flag *flag)
{
	flag = (struct s_flag *)malloc(sizeof(t_flag));
	flag->t = 0;
	flag->r = 0;
	flag->l = 0;
	flag->rr = 0;
	flag->a = 0;
	return (flag);
}

void	ft_free_all_arg(t_arg *arg, t_flag *flag)
{
	t_arg	*tmp;

	while (arg->prev)
		arg = arg->prev;
	while (arg)
	{
		tmp = arg;
		arg = arg->next;
		free(tmp->path);
		free(tmp);
	}
	free(flag);
}

int		main(int argc, char **argv)
{
	t_flag	*flag;
	t_arg	*arg;
	t_arg	*first;
	int		multiple_arg;

	g_error = 0;
	arg = NULL;
	flag = NULL;
	multiple_arg = 0;
	flag = ft_set_zero(flag);
	if (ft_parsing(argc, argv, &arg, flag))
		return (-1);
	if (arg->next)
		multiple_arg = 1;
	first = arg;
	while (arg)
	{
		ft_ls(arg->path, flag, multiple_arg);
		arg = arg->next;
	}
	ft_free_all_arg(first, flag);
	return (g_error);
}
