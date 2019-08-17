/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:32:19 by wstygg            #+#    #+#             */
/*   Updated: 2019/08/08 17:32:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void			delete_latent_file(t_data *data)
{
	t_ls *head = data->ls;
	t_ls *temp = head;
	t_ls		*helping;

	while (temp)
	{
		helping = temp;
		if (temp->entry->d_name[0] == '.')
		{
			if (temp == head) // если элемент который надо удалить первый
				head = temp->next;
			else
				helping->next = temp->next;
			free(temp);
		}
		temp = temp->next;
	}
	data->ls = head;
}

void				rev_struct(t_data *data)
{
	t_ls *ls;

	ls = data->ls;
	t_ls *current;
	t_ls *prev = NULL;
	t_ls *next = NULL;
	t_ls *tmp;


	current = ls;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	data->ls = prev;
}

char				*path_normalize(char **path, int flag)
{
	char			*ret;
	size_t			len;
	size_t			i;

	len = ft_strlen(*path);
	while ((*path)[--len] == '/')
		;
	len++;
	ret = malloc(len + 2);
	i = -1;
	while (++i < len)
		ret[i] = (*path)[i];
	ret[len] = '/';
	ret[len + 1] = '\0';
	if (flag)
		free(*path);
	return (ret);
}

t_ls				*fill_first(struct dirent *entry, char *path)
{
	char			*fullpath;
	t_ls			*ls;

	ls = malloc(sizeof(t_ls));
	ls->next = NULL;
	ls->entry = entry;
	fullpath = ft_strjoin(path, entry->d_name);
	fullpath = path_normalize(&fullpath, 1);
	lstat(fullpath, &ls->stat);
	free(fullpath);
	return (ls);
}

t_ls				*add_one(struct dirent *entry, char *path)
{
	t_ls			*ret;
	char			*fullpath;

	if (!(ret = malloc(sizeof(t_ls))))
		return (NULL);
	ret->entry = entry;
	fullpath = ft_strjoin(path, entry->d_name);
	lstat(fullpath, &ret->stat);
	ret->next = NULL;
	free(fullpath);
	return (ret);
}
