# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 20:42:04 by jaleman           #+#    #+#              #
#    Updated: 2018/10/23 20:42:05 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

INC_DIR = ./includes/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

INC     = $(INC_DIR)
SRC     = ft_putchar_fd.c
OBJ     = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
LFLAGS  = -I.
AR      = ar rc
RLIB    = ranlib

all:	obj $(NAME)
obj:
		@mkdir -p $(OBJ_DIR)
$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@$(RLIB) $(NAME)
		@echo "[INFO] $(NAME) created!"
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INC)
clean:
		@rm -rf $(OBJ) $(OBJ_DIR)
		@echo "[INFO] Objects removed!"
fclean: clean
		@rm -rf $(NAME)
		@echo "[INFO] Library [$(NAME)] removed!"
re:	fclean all
.PHONY: all clean fclean re
