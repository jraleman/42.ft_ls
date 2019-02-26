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

NAME = ft_ls
SRC =	src/main.c \
		src/ft_ls.c \
		src/t_file/file_add.c \
		src/t_file/file_del.c \
		src/t_file/file_dir.c \
		src/t_file/file_ini.c \
		src/t_file/file_srt.c \
		src/t_file/file_swp.c \
		src/t_file/file_len.c \
		src/t_path/path_add.c \
		src/t_path/path_del.c \
		src/t_path/path_len.c \
		src/t_path/path_srt.c \
		src/t_path/path_swp.c \
		src/utils/cmp_ts_n.c \
		src/utils/create_file.c \
		src/utils/delete_files.c \
		src/utils/print/print_date.c \
		src/utils/print/print_list.c \
		src/utils/print/print_name.c \
		src/utils/print/print_type.c \
		src/utils/print/print_entry.c \
		src/utils/print/print_perm.c
CC = gcc
CFLAGS = -I includes/ -I libft/ -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
DEBUG = #-g3 -fsanitize=address

all: $(NAME)
%.o: %.c
	@printf "[ft_ls] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ft_ls] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[ft_ls] Compiled successfuly! [OK]\n"
	@make -C libft/
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) libft/libft.a -o $(NAME)
clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[ft_ls] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@make nofclean -C libft/
	@printf "[ft_ls] Removed ft_ls binary!\n"
re: fclean all

.PHONY: all clean fclean re
