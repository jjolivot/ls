/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:15:20 by jjolivot          #+#    #+#             */
/*   Updated: 2018/07/28 20:11:34 by jjolivot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_tab_size(char **tab);
int					ft_power(int nbr, int power);
int					ft_10_to_8(int start);
void				ft_print_words_tables(char **tab);
void				ft_all_free(char **tab);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memset(void *b, int c, size_t len);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
int					ft_is_alpha_sort(char *a, char *b);
size_t				ft_strlen(const char *str);
void				ft_lstadd(t_list **alst, t_list *ne);
int					ft_digitnbr(int n);
int					ft_rtn_bigger(int a, int b);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_rtn_smaller(int a, int b);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_rtn_smaller(int a, int b);
int					ft_toupper(int c);
char				*ft_f_strjoin(char *s1, char const *s2);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isdigit(int c);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memalloc(size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_wc(char *str, char c);
int					ft_wl(char *s, int count, char c);
int					ft_isprint(int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
int					ft_isalnum(int c);
char				*ft_strnew(size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isascii(int c);
char				*ft_strtrim(char const *s);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
#endif
