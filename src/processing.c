/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:51 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/17 15:02:44 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file 	*get_info(char *dir, struct dirent *readfile)
{
	t_file *file;

	if (!(file = malloc(sizeof(t_file))))
		return (0);
	ft_strcpy(file->file_name, readfile->d_name);
	file->path = ft_strdup(dir);
	lstat(file->path, file->stat);
	file->next = NULL;
	return (file);
}

void	ft_getls(char *dir, t_file **file)
{
	DIR* rep;
	struct dirent *readfile;
	t_file	*cpy;

	if (!(rep = opendir(dir)))
			return ;
	cpy = NULL;
	while ((readfile = readdir(rep)))
	{
		if (cpy)
		{
			cpy->next = get_info(dir, readfile);
			cpy = cpy->next;
		}
		else
		{
			cpy = get_info(dir, readfile);
			*file = cpy;
		}
	}
}

t_file	*ft_getrecurls(char *dir)
{
	DIR* rep;
	struct dirent *readfile;
	t_file	*file;
	t_file	*cpy;

	if (!(rep = opendir(dir)))
			return (NULL);
	cpy = NULL;
	while ((readfile = readdir(rep)))
	{
		if (cpy)
		{
			cpy->next = get_info(dir, readfile);
			cpy = cpy->next;
		}
		else
		{
			cpy = get_info(dir, readfile);
			file = cpy;
		}
		if (readfile->d_type == 4 && readfile->d_name[0] != '.')
			cpy->inside = ft_getrecurls(ft_strjoin(dir, readfile->d_name));
	}
	return (file);
}

int	process(t_ls *data)
{
	int	i;

	i = -1;
	if (!(data->files = malloc(sizeof(t_file) * data->nb_dir)))
		return (0);
	while (++i < data->nb_dir)
	{
		if (!data->fg_br)
			ft_getls(data->dir[i], &(data->files[i]));
		else
			data->files[i] = ft_getrecurls(data->dir[i]);
	}
	return(1);
}
