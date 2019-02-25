NAME   = libft.a
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I . -I ft_printf/

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
OBJ     = $(SRC:.c=.o) 

all: $(NAME)

%.o: %.c
	@printf "\x1B[0;32m[Libft] Compilation [o.] \r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\x1B[0;32m[Libft] Compilation [.o] \r"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\x1B[0;32m[Libft] Compilation [OK]\n"

clean:
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[Libft] Deleted *.o\n"

nofclean:
	@/bin/rm -f $(NAME)
	@printf "\033[0;31m[Libft] Deleted libft.a\n"

fclean: nofclean clean

re: fclean all
