/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:54:07 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:02:01 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*alst)->next;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = tmp2;
	}
	ft_lstdelone(&tmp, del);
	ft_lstdelone(alst, del);
}
