/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Returns a directory or a file depending on the type give as argument.
*/

t_file		*create_file(char *path, char *opt, int type)
{
	t_file		*file;

	file = (type == 1 ? file_dir(path, opt) : file_ini(path));
	file = file_srt(file, opt);
	return (file);
}
