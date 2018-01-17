/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:17:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/17 13:50:50 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include <dirent.h>
#include "libft.h"

typedef struct		s_file 
{
#ifdef _DARWIN_FEATURE_64_BIT_INODE
	char			file_name[1024];
#else
	char			file_name[256];
#endif
	char			*path;
	struct stat		*stat;
	struct s_file	*inside;
	struct s_file	*next;
}					t_file;

typedef struct		s_ls
{
	int				fg_l;
	int				fg_a;
	int				fg_br;
	int				fg_sr;
	int				fg_t;
	int				nb_dir;
	char			**dir;
	t_file			**files;
}					t_ls;


#endif
