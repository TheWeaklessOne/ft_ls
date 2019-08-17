/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:32:55 by wstygg            #+#    #+#             */
/*   Updated: 2019/08/08 17:32:56 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_ls				*fill_dir(char *path, t_ls *ls, t_data *data)
{
	struct dirent	*entry;
	DIR				*dir;
	char			*fullpath;
	t_ls			*ls_head;

	path = path_normalize(&path, 0);
	if (!(dir = opendir(path)))
		return (NULL);
	entry = readdir(dir);
	ls = fill_first(entry, path);
	ls_head = ls;
	while ((entry = readdir(dir)))
	{
		ls->next = add_one(entry, path);
		ls = ls->next;
		if (data->flags[LS_RB] && ft_strcmp(".", ls->entry->d_name) && ft_strcmp("..", ls->entry->d_name) && S_ISDIR(ls->stat.st_mode))
		{
			fullpath = ft_strjoin(path, ls->entry->d_name);
			ls->next = fill_dir(fullpath, ls->next, data);
			while (ls->next)
                ls = ls->next;
        free(fullpath);
        }
	}
	free(path);
	closedir(dir);
	return (ls_head);
}
