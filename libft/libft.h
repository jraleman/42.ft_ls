/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** List of globlal variables.
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

static const unsigned long	g_mask01;
static const unsigned long	g_mask80;

# endif

/*
** Prototypes
*/

int					ft_atoi(const char *str);
int					ft_cisin(char *s, char c);
void				ft_putchar(char c);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char**as);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_strlower(char *s);
char				*ft_strncat(char *restrict s1, const char *restrict s2, \
					size_t n);
char				*ft_strndup(const char *s, int size);
char				*ft_strnew(size_t size);
int					ft_printf(const char *s, ...);
int					ft_dprintf(int fd, const char *format, ...);
char				*ft_zprintf(const char *format, ...);

#endif
