/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ts_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Compare timestap vs name.
** Returns :
**   - If time is equal, return the difference between the names.
**   - If time is different, return the difference between the times.
*/

int			cmp_ts_n(int a, int b, char *s1, char *s2)
{
	return (a == b ? ft_strcmp(s1, s2) : a - b);
}
