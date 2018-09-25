/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:25:09 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 17:29:12 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

struct s_arg	*ft_invert_list(struct s_arg *maillon)
{
	struct s_arg	*tmp;
	int				i;

	i = 0;
	while (maillon->prev || i++ == 0)
	{
		tmp = maillon->next;
		maillon->next = maillon->prev;
		maillon->prev = tmp;
		if (tmp)
			maillon = tmp;
	}
	return (maillon);
}

int				ft_parsing(int argc, char **argv, t_arg **arg, t_flag *flag)
{
	if (ft_pars_error(argc, argv, flag))
		return (1);
	ft_arg_to_list(argc, argv, arg);
	if ((*arg)->next)
	{
		(*arg) = ft_sort(arg);
		(*arg) = ft_sort_file_and_dir(arg, flag);
	}
	ft_check_fexist(arg);
	if (flag->t)
		(*arg) = ft_time_sort(arg, flag);
	if (flag->r)
		*arg = ft_invert_list(*arg);
	if ((*arg)->next)
		(*arg) = ft_sort_file_and_dir(arg, flag);
	return (0);
}

t_arg			*ft_arg_join(t_arg *arg, char *path)
{
	t_arg *new;

	new = NULL;
	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		exit(0);
	new->prev = arg;
	new->path = ft_strdup(path);
	if (arg)
		arg->next = new;
	new->next = NULL;
	return (new);
}

int				ft_arg_to_list(int argc, char **argv, t_arg **ar)
{
	int		i;
	t_arg	*arg;

	arg = NULL;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] && argv[i][1] != '-')
		i++;
	if (i < argc && argv[i][1] == '-')
		i++;
	while (i < argc)
	{
		arg = ft_arg_join(arg, argv[i]);
		i++;
	}
	if (arg == 0)
		arg = ft_arg_join(arg, ".");
	while (arg && arg->prev)
		arg = arg->prev;
	if (arg)
		*ar = arg;
	return (0);
}
