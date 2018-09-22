/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 22:20:56 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/20 22:24:32 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char	ft_filetype(int mod)
{
	if (S_ISREG(mod))
		return ('-');
	if (S_ISDIR(mod))
		return ('d');
	if (S_ISLNK(mod))
		return ('l');
	if (S_ISCHR(mod))
		return ('c');
	if (S_ISBLK(mod))
		return ('b');
	if (S_ISFIFO(mod))
		return ('p');
	if (S_ISSOCK(mod))
		return ('s');
	return ('?');
}

char	*ft_file_and_permissions(int mod)
{
	char *str;

	str = (char *)malloc(sizeof(str) * 10 + 1);
	str[0] = ft_filetype(mod);
	str[1] = (S_IRUSR & mod ? 'r' : '-');
	str[2] = (S_IWUSR & mod ? 'w' : '-');
	str[3] = (S_IXUSR & mod ? 'x' : '-');
	str[4] = (S_IRGRP & mod ? 'r' : '-');
	str[5] = (S_IWGRP & mod ? 'w' : '-');
	str[6] = (S_IXGRP & mod ? 'x' : '-');
	str[7] = (S_IROTH & mod ? 'r' : '-');
	str[8] = (S_IWOTH & mod ? 'w' : '-');
	str[9] = (S_IXOTH & mod ? 'x' : '-');
	if (S_ISVTX & mod && str[9] == 'x')
		str[9] = 't';
	else if (S_ISVTX & mod)
		str[9] = 'T';
	str[10] = '\0';
	return (str);
}
