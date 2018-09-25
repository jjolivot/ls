/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:38:31 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:02:48 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	new_list->next = (ft_lstmap(lst->next, f));
	return (new_list);
}
