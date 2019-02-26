/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_replace(char *s, char c1, char c2, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		if (s[count] == c1)
		{
			s[count] = c2;
			return ;
		}
		count++;
	}
}

int		lenall(t_printf *lst)
{
	int nb;

	nb = 0;
	while (lst)
	{
		nb += lst->len;
		lst = lst->next;
	}
	return (nb);
}
