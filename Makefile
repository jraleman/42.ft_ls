# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 16:42:05 by jaleman           #+#    #+#              #
#    Updated: 2018/10/23 16:42:06 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME      = ft_ls

# Compiling flags
FLAGS     = -Wall -Wextra -Werror -g -Ofast

# Directories
SRC_DIR   = ./src/
OBJ_DIR   = ./obj/
INC_DIR   = ./includes/

# Files
SRC_FILES = main.c ft_ls.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Library
LIB_DIR   = ./libft/
LIB_BIN   = libft.a
LIB_INC   = includes

# Paths
SRC       = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ       = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIB       = $(addprefix $(LIB_DIR), $(LIB_BIN))

# Linker
LNK       = -L $(LIB_DIR) -lft

# Rules
all: obj $(LIB) $(NAME)
obj:
		@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@gcc $(FLAGS) -I $(LIB_DIR)$(LIB_INC) -I $(INC_DIR) -o $@ -c $<
$(LIB):
	  @make -C $(LIB_DIR)
$(NAME): $(OBJ)
		@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
		@gcc $(OBJ) $(LNK) -o $(NAME)
		#	@gcc $(OBJ) $(LNK) -lm -fsanitize=address -o $(NAME)
		@echo "(•̀ᴗ•́)و $(NAME) generated!"
clean:
		@rm -Rf $(OBJ_DIR)
		@echo "¯\_(ツ)_/¯ Objects removed!"
fclean: clean
		@rm -f $(NAME)
		@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removed!"
re: fclean all

# Phony
.PHONY: all clean fclean re
