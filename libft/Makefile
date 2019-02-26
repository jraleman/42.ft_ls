# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jraleman@student.42.us.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#              #
#    Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libft.a
SRC    = ft_atoi.c \
		 ft_cisin.c \
		 ft_putchar.c \
		 ft_strcat.c \
  		 ft_strcmp.c \
  		 ft_strcpy.c \
  		 ft_strdel.c \
  		 ft_strdup.c \
  		 ft_strlen.c \
  		 ft_strlower.c \
  		 ft_strncat.c \
  		 ft_strncat.c \
  		 ft_strndup.c \
  		 ft_strnew.c \
  		 ft_printf/ft_printf.c \
  		 ft_printf/pf_base.c \
  		 ft_printf/pf_ftoa.c \
  		 ft_printf/pf_len.c \
  		 ft_printf/pf_options.c \
  		 ft_printf/pf_parsing.c \
  		 ft_printf/pf_put.c \
  		 ft_printf/pf_router.c \
  		 ft_printf/pf_struct.c \
  		 ft_printf/pf_utils.c
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I . -I ft_printf/
OBJ     = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	@printf "[Libft] Compiling [:.]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[Libft] Compiling [.:]\r"
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "[Libft] Compiled successfuly! [OK]\n"
clean:
	@/bin/rm -f $(OBJ)
	@printf "[Libft] Removed object files!\n"
nofclean:
	@/bin/rm -f $(NAME)
	@printf "[Libft] Removed libft binary!\n"
fclean: nofclean clean
re: fclean all

.PHONY: all clean fclean re
