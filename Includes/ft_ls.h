/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:36:53 by wstygg            #+#    #+#             */
/*   Updated: 2019/08/08 17:36:54 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FT_LS_H
# define TEST_FT_LS_H

# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <time.h>
# include <stdlib.h>
# include <zconf.h>
#include <pwd.h>
#include <grp.h>


enum				e_flags
{
	LS_L = 0,
	LS_RB,
	LS_RS,
	LS_A,
	LS_T
};

typedef struct		s_ls
{
	mode_t			mode;
	off_t			size;
	time_t			time;
	nlink_t			st_nlink;
	gid_t			st_gid;
	struct dirent	*entry;
	struct s_ls		*next;
	struct stat		stat;
}					t_ls;

typedef	struct		s_data
{
	t_ls			*ls;
	int				flags[5];
}					t_data;

char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);

t_ls				*add_one(struct dirent *entry, char *path);
char				*path_normalize(char **path, int flag);
void				rev_struct(t_data *data);
t_ls				*fill_dir(char *path, t_ls *ls, t_data *data);
t_ls				*fill_first(struct dirent *entry, char *path);
int					fill_flags(const char *str, t_data *data);
void 				check_flags(t_data *data);
void				vivod(t_data *data);
void				delete_latent_file(t_data *data);
char				*ft_write_to_str(char *str, t_data *data);
char				*ft_write_with_l(char *str, t_data *data);

#endif
