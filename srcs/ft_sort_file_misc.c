/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_file_misc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 21:29:54 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/24 21:24:03 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_same_day(char *tmp, time_t maillon, time_t second)
{
	char		*maill;
	char		*sec;
	char		*current;
	time_t		i;

	i = time(0);
	current = ctime(&i);
	i = 0;
	maill = ft_strsub(ctime(&maillon), 0, 10);
	(tmp = ft_strsub(ctime(&maillon), 20, 4));
	maill = ft_f_strjoin(maill, tmp);
	free(tmp);
	sec = ft_strsub(ctime(&second), 0, 10);
	tmp = ft_strsub(ctime(&second), 20, 4);
	sec = ft_f_strjoin(sec, tmp);
	free(tmp);
	if (!ft_strcmp(maill, sec))
		i = 1;
	free(maill);
	free(sec);
	maill = ctime(&maillon);
	sec = ctime(&second);
	if (!ft_strcmp(sec, maill))
		i = 0;
	return (i);
}

struct s_file	*ft_merge_time_suite(struct s_file *mail, struct s_file *sec)
{
	t_file	*res;

	res = mail;
	res->next = ft_merge_time_nf(mail->next, sec);
	if (res->next)
		res->next->prev = res;
	return (res);
}
