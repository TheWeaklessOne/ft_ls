/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:33:45 by wstygg            #+#    #+#             */
/*   Updated: 2019/08/08 17:33:46 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int				main(int ac, char *av[])
{
	t_data		data;
	int			args;

	args = 0;
	while (++args < ac)
	{
		if (!fill_flags(av[args], &data))
			data.ls = fill_dir(av[args], data.ls, &data);
	}
	!data.ls ? data.ls = fill_dir(".", data.ls, &data) : 0;
	check_flags(&data);
	return (0);
}
