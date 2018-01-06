/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:06:35 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/01/06 00:49:21 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define NOT_F 1
# define RED "\033[31m"
# define ROSE "\033[35m"
# define YELLOW "\033[33m"
# define CANCEL "\033[00m"
# define CYAN "\033[36m"
# define BOLD "\033[00;1m"
# define GREEN "\033[32m"
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <grp.h>
# include <errno.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_flags
{
	int				l;
	int				a;
	int				upp_r;
	int				r;
	int				t;
	int				err;
	int				big_g;
	int				p;
	int				big_t;
	int				m;
	int				one;
	int				args_nbr;
	int				frst;
	int				o;
	char			invalid_o;
}					t_flags;

typedef struct		s_info
{
	char			*d_name;
	int				d_type;
	char			*st_size;
	time_t			mtime;
	char			*st_nlink;
	long long		st_blocks;
	char			*pw_name;
	char			*gr_name;
	char			*rights;
	char			*m_date;
	char			**d_date;
	char			*path;
	struct s_info	*next;
}					t_info;

typedef struct		s_data
{
	char			*abs_path;
	char			*f_name;
	DIR				*dir;
	struct stat		stat;
	struct dirent	*file;
	struct passwd	*getpwuid;
	struct group	*group;
}					t_data;

typedef struct		s_args
{
	t_list			*list;
	t_info			*files;
	t_info			*dir;
	t_flags			flag;
}					t_args;

/*
** core.c
*/

int					recursive(t_info *files, t_info *dir, t_flags *flag);

/*
** ft_ls.c
*/

int					get_args(t_list *list, t_info **files, t_info **dir,\
		t_flags *flag);
int					get_and_check_args(char **av, int *i, int ac, t_args *args);
void				deal_with_dirs(t_flags *flag, char *dir_name);
int					core_program(t_info *files, t_info *dir, t_flags *flag);
int					ft_ls(int ac, char **av);

/*
** processing_chained_list.c
*/

char				*get_rights(t_data *data);
int					lstlen(t_info *info);
t_info				*addelem(t_data *data);
void				lstaddend(t_info **info, t_data *data);
int					all_in_one_info(char *path, t_info **info, t_data *data,\
		t_flags *flag);

/*
** sort_list.c
*/

void				swap_values(t_info *dest, t_info *src);
void				sort_list_by_name(t_info **info, int size_list);
void				sort_list_by_time(t_info **info);
void				reverse_list(t_info **list);
void				sort_list(t_info **info, t_flags *flag);

/*
** check_flags.c
*/

void				fill_flags(char c, t_flags *flag);
int					check_first_char(char *av);
int					check_good_char(char *tmp, t_flags *flag);
int					check_flags(char **av, int ac, int *arg, t_flags *flag);

/*
** display_errors.c
*/

void				display_dir_error(char *dir_name);
void				no_file_or_directory(char *str);
void				illegal_option(char c);
void				free_info(t_info **info);
void				free_list(t_list **list);

/*
** tools.c
*/

int					f_wordtab(int *word, t_info *tmp);
void				what_display(char *s1, char *s2, t_flags *flag, int var);
void				print_spaces(int *word, char *s, int index);
int					get_total(t_info *info, t_flags *flag);
int					get_lgst_word(int *word, t_info *info, t_flags *flag);

/*
** tools_snd.c
*/

void				put_color(char c);
int					get_min_maj(t_data *data, t_info *new);
void				free_values(t_info *now);
void				check_acl(char *path);
int					get_argmode(t_data *data);

/*
** display_ls.c
*/

int					display_smb_link(t_info *tmp);
void				display_date(char **date, int *word, int val,\
		t_flags *flag);
void				display_details(t_info *tmp, int *word, t_flags *flag);
void				display_files(t_info *info, t_flags *flag);
void				display_list(t_info *info, t_flags *flag);

/*
** recursive.c
*/

int					check_hiddir(t_info *info, t_flags *flag, char *dir_n);
void				do_recursion(char *dir_name, t_flags *flag);
int					recursive(t_info *files, t_info *dir, t_flags *flag);

#endif
