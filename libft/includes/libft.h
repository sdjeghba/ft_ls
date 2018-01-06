/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:32:38 by sdjeghba          #+#    #+#             */
/*   Updated: 2017/12/30 06:06:42 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MAX_NBR 2147483647
# define MIN_NBR -2147483648
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

/*
** part one
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);

/*
**part two
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_memprint(void *ptr, size_t size);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);

/*
** chained list
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del) (void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstpushback(void const *content, size_t content_size,\
		t_list **list);
int					ft_lstlen(t_list **list);
void				ft_lstsortbyname(t_list **list);
void				ft_lstsortrev(t_list **list);
void				ft_display_list(t_list **list);

/*
** extras functions
*/

void				ft_swap(char *a, char *b);
char				*ft_strrev(char *str);
int					ft_power(int nb, int power);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_place_between_str(char *s1, char *s2, char *c);
void				ft_display_tab(char **tab);
int					ft_get_tab_height(char **tab);
char				**ft_copy_tab(char **tab);
void				ft_free_tab(char **tab);
char				*ft_strrealloc(char *str, int size);
int					get_next_line(int fd, char **line);
int					ft_count_word(char *s, char c);
void				ft_putdblstr(char *s1, char *s2);
void				ft_putendblstr(char *s1, char *s2);

#endif
