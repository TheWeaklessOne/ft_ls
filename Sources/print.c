/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:48:18 by plettie           #+#    #+#             */
/*   Updated: 2019/08/11 23:48:19 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char		*ft_write_to_str(char *str, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->ls != NULL && (!(data->flags[LS_L])))
	{
		while(data->ls->entry->d_name[i])
		{
			str[j] = data->ls->entry->d_name[i];
			i++;
			j++;
		}
		str[j] = '\t';
		j++;
		i = 0;
		data->ls = data->ls->next;
	}
	if (data->flags[LS_L])
		str = ft_write_with_l(str, data);
	return (str);
}

void		vivod(t_data *data)
{
	char *str;
	int j;
	int len;

	if (data->flags[LS_L])
		free(str);
	str = malloc(sizeof(char *) * 20000);
	str = ft_write_to_str(str, data);
	len = ft_strlen(str);
	j = 0;
	while (j < len)
	{
		write(1, &str[j], 1);
		j++;
	}
	free(str);
}