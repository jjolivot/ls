/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:03:23 by jjolivot          #+#    #+#             */
/*   Updated: 2017/12/06 20:00:18 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	else
	{
		if (!(new_list->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(new_list->content, (void *)content, content_size);
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	return (new_list);
}
