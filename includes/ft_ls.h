/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:06:21 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/12 15:46:26 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <errno.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct	s_flag
{
	int			l;
	int			R;
	int			r;
	int			t;
	int			a;
}				t_flag;

typedef struct	s_arg
{
	struct s_arg		*prev;
	char				*path;
	struct s_arg		*next;
}				t_arg;

typedef struct	s_file
{
	struct s_file	*prev;
	struct stat		*buf;
	char			*name;
	char			*path;
	int				mod;
	size_t			total_size;
	int				islink;
	int				link;
	int				minor;
	int				major;
	char			filetype;
	int				size;
	int				modif_time;
	struct s_file	*next;
}				t_file;

int				ft_pars_error(int argc, char **argv, t_flag  *flag);
char			*ft_path_convert(char *path);
t_file			*ft_info(t_file *prev, int mustlink, char *path, int (stati)(const char *, struct stat *));
t_file			*ft_info_link(char *path, int  (stati)(const char *,
			struct stat *), t_flag flag);
void			ft_free_file(t_file *file);
void			ft_arg_print(t_arg *arg);
void			ft_permission_denied(char *path);
void			ft_list_display(t_file *file, t_flag flag);
int				ft_is_file(t_arg **maillon, t_flag flag);
void			ft_free_all_files(t_file *file);
struct s_arg	*ft_time_sort(struct s_arg **maillon, t_flag flag);
struct s_arg	*ft_sort(struct s_arg **maillon);
int				ft_display(t_file *file, t_flag flag);
struct s_arg	*ft_sort_file_and_dir(struct s_arg **maillon, t_flag flag);
int				ft_ls(char *path, t_flag flag, int multiple_arg);
int				ft_arg_to_list(int argc, char **argv, t_arg **arg);
int				ft_parsing(int argc, char **argv, t_arg **arg, t_flag *flag);
