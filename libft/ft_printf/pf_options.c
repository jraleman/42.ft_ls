/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_addc(char *s, int n, char c)
{
	int count;

	count = 0;
	while (count < n)
		s[count++] = c;
	s[count] = '\0';
	return (s);
}

char	*add_base_prefix(t_opt opt, char *s)
{
	if (opt.nb_zero == 2)
		ft_strcat(s, "0X");
	else if (opt.nb_zero == 1)
		ft_strcat(s, "0");
	return (s);
}

char	*pf_options(char *s, t_opt opt)
{
	char *tmp;

	tmp = s;
	pf_addc(opt.tmp, opt.nb_sp + opt.nb_p, ' ');
	ft_strcat(opt.tmp, opt.sign);
	add_base_prefix(opt, opt.tmp);
	pf_addc(opt.tmp + opt.nb_sp + opt.nb_zero + opt.nb_p
			+ opt.nb_sig, opt.nb_0, '0');
	if (tmp[0] == '-' && opt.nb_sig)
		tmp++;
	ft_strncat(opt.tmp, tmp, opt.size);
	pf_addc(opt.tmp + opt.size + opt.nb_0 + opt.nb_sp
			+ opt.nb_zero + opt.nb_p + opt.nb_sig, opt.nb_spe, ' ');
	return (opt.tmp);
}
