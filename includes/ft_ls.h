/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:06:21 by jjolivot          #+#    #+#             */
/*   Updated: 2018/09/25 17:58:29 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <grp.h>
# include <dirent.h>
# include <pwd.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>

int				g_error;

typedef struct	s_flag
{
	int			l;
	int			rr;
	int			r;
	int			t;
	int			a;
}				t_flag;

typedef struct	s_arg
{
	struct s_arg		*next;
	struct s_arg		*prev;
	char				*path;
}				t_arg;

typedef struct	s_file
{
	char			*name;
	char			*path;
	char			filetype;
	int				maxgrpsize;
	int				maxusrsize;
	int				mod;
	int				islink;
	int				link;
	int				minor;
	int				major;
	int				size;
	int				modif_time;
	size_t			total_size;
	struct group	*grp;
	struct passwd	*passwd;
	struct s_file	*next;
	struct s_file	*prev;
	struct stat		*buf;
}				t_file;

int				ft_pars_error(int argc, char **argv, t_flag *flag);
struct s_file	*ft_merge_time_nf(struct s_file *maillon,
				struct s_file *second);
int				ft_bad_arg_error(char c);
int				ft_same_day(char *tmp, time_t maillon, time_t second);
struct s_file	*ft_merge_time_suite(struct s_file *mail, struct s_file *sec);
char			ft_filetype(int mod);
char			*ft_file_and_permissions(int mod);
t_file			*ft_file_add(t_file *file);
t_file			*ft_file_new(void);
int				ft_empty_arg_error();
struct s_file	*ft_split(struct s_file *maillon);
struct s_file	*ft_merge_sort_file(struct s_file *maillon, struct s_file
				*(ft_merge)(struct s_file *maillon, struct s_file *second));
struct s_file	*ft_total_size(struct s_file *file);
struct s_file	*ft_sort_file(struct s_file *file, t_flag *flag);
struct s_file	*ft_merge_alpha(struct s_file *maillon, struct s_file *second);
struct s_file	*ft_merge_time(struct s_file *maillon, struct s_file *second);
struct s_file	*ft_reverse_file(struct s_file *file);
struct s_file	*ft_sort_time_file(struct s_file *file);
void			ft_inverse_file(struct s_file *maillon);
t_file			*ft_file_new(void);
char			*ft_path_convert(char *path);
t_file			*ft_info(t_file *prev, int mustlink, char *path,
				int (stati)(const char *, struct stat *));
t_file			*ft_info_link(char *path, int (stati)(const char *,
				struct stat *), t_flag *flag);
void			ft_free_file(t_file *file);
void			ft_arg_print(t_arg *arg);
void			ft_permission_denied(char *path);
void			ft_check_fexist(struct s_arg **maillon);
struct s_file	*ft_sort_file(struct s_file *file, t_flag *flag);
void			ft_list_display(t_file *file, t_flag *flag);
int				ft_is_file(t_arg **maillon, t_flag *flag);
void			ft_free_all_files(t_file *file);
struct s_arg	*ft_time_sort(struct s_arg **maillon, t_flag *flag);
struct s_arg	*ft_sort(struct s_arg **maillon);
int				ft_display(t_file *file, t_flag *flag);
struct s_arg	*ft_sort_file_and_dir(struct s_arg **maillon, t_flag *flag);
int				ft_ls(char *path, t_flag *flag, int multiple_arg);
int				ft_arg_to_list(int argc, char **argv, t_arg **arg);
int				ft_parsing(int argc, char **argv, t_arg **arg, t_flag *flag);
#endif
