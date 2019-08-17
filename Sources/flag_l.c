/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:10:37 by plettie           #+#    #+#             */
/*   Updated: 2019/08/12 06:10:39 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char		check_first_mode(int mode)
{

	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

void		check_mode(char *str, int mode)
{
	str[0] = check_first_mode(mode);
	str[1] = (S_IRUSR & mode) ? 'r' : '-';
	str[2] = (S_IWUSR & mode) ? 'w' : '-';
	str[3] = (S_IXUSR & mode) ? 'x' : '-';
	str[4] = (S_IRGRP & mode) ? 'r' : '-';
	str[5] = (S_IWGRP & mode) ? 'w' : '-';
	str[6] = (S_IXGRP & mode) ? 'x' : '-';
	str[7] = (S_IROTH & mode) ? 'r' : '-';
	str[8] = (S_IWOTH & mode) ? 'w' : '-';
	str[9] = (S_IXOTH & mode) ? 'x' : '-';
	str[10] = '\0';
}

static void		display_time(t_ls *ls)
{
	time_t	today;
	char	*s;

	time(&today);
	s = ctime(&(ls->time)) + 4;
	write(1, s, 12);
}

char		*ft_write_with_l(char *str, t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	check_mode(str, data->ls->stat.st_mode);
	write(1, str, 10);
	i += 10;
	printf("%hu\t", data->ls->st_nlink);
	while (getgrgid(data->ls->st_gid)->gr_name[k])
	{
		write(1, &getgrgid(data->ls->st_gid)->gr_name[k], 1);
		//i++;
		k++;
	}
	str[i] = '\t';
	i++;
	printf("%lld\t", data->ls->size);
	display_time(data->ls);
	while(data->ls->entry->d_name[j])
	{
		write(1, &data->ls->entry->d_name[j], 1);
		i++;
		j++;
	}
	return (str);
}
