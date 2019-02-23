NAME = ft_ls 

SRC =	src/main.c \
		src/ft_ls.c \
		\
		src/t_file/file_add.c \
		src/t_file/file_del.c \
		src/t_file/file_dir.c \
		src/t_file/file_ini.c \
		src/t_file/file_srt.c \
		src/t_file/file_swp.c \
		\
		src/t_path/path_add.c \
		src/t_path/path_del.c \
		src/t_path/path_len.c \
		src/t_path/path_srt.c \
		src/t_path/path_swp.c \
		\
		src/utils/print/print_date.c \
		src/utils/print/print_list.c \
		src/utils/print/print_name.c \
		src/utils/print/print_type.c \
		src/utils/print/print_perm.c \
		\
		src/utils/sort/compare.c \
		src/utils/sort/file_sort_atime.c \
		src/utils/sort/file_sort_ctime.c \
		src/utils/sort/file_sort_mtime.c \
		src/utils/sort/file_sort_name.c \
		src/utils/sort/file_sort_size.c \
		src/utils/sort/path_sort_atime.c \
		src/utils/sort/path_sort_ctime.c \
		src/utils/sort/path_sort_mtime.c \
		src/utils/sort/path_sort_name.c \
		src/utils/sort/path_sort_size.c \

CC = gcc

CFLAGS = -I includes/ -I libft/ -Wall -Werror -Wextra
DEBUG = #-g3 -fsanitize=address

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@printf "\033[0;32m[ft_ls] Compilation [o.]\033[0;0m\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[ft_ls] Compilation [.o]\033[0;0m\r"

check:
	-@cat $(SRC) | grep ft_strnew	| grep -v "if (\!(" 
	-@cat $(SRC) | grep ft_strdup 	| grep -v "if (\!(" 
	-@cat $(SRC) | grep ft_strndup	| grep -v "if (\!(" 
	-@cat $(SRC) | grep malloc    	| grep -v "if (\!(" 
	-@cat $(SRC) | grep printf		| grep -v ft_printf	| grep -v t_printf
	@norminette $(SRC)

$(NAME): $(OBJ)
	@printf "\033[0;32m[ft_ls] Compilation [OK]\033[0;0m\n"
	@make -C libft/
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[ft_ls] Deleted *.o\033[0;0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make nofclean -C libft/
	@printf "\033[0;31D[ft_ls] Deleted ft_ls\033[0;0m\n"

re: fclean all

.PHONY: all clean fclean re
