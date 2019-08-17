/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:05:40 by wstygg            #+#    #+#             */
/*   Updated: 2019/08/08 18:05:41 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void 			check_flags(t_data *data)
{
	if (!data->flags[LS_A])
		delete_latent_file(data);
	if(data->flags[LS_RS])
		rev_struct(data);
	vivod(data);
}

void			add_flag(const char c, t_data *data)
{
	if (c == 'l')
		data->flags[LS_L] = 1;
	if (c == 'R')
		data->flags[LS_RB] = 1;
	if (c == 'r')
		data->flags[LS_RS] = 1;
	if (c == 'a')
		data->flags[LS_A] = 1;
	if (c == 't')
		data->flags[LS_T] = 1;
}

int				fill_flags(const char *str, t_data *data)
{
	int			i;
	const char	flags[] = "lRart";

	i = 0;
	if (str[i++] == '-' && str[i])
	{
		while (str[i])
		{
			if (ft_strchr(flags, str[i]))
				add_flag(str[i], data);
			else
			{
				write(1, "ft_ls: illegal option -- ", 25);
				write(1, str + i, 1);
				write(1, "\nusage: ls [-Ralrt] [file ...]\n", 31);
				exit(0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
