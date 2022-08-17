# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 11:23:15 by bkrasnos          #+#    #+#              #
#    Updated: 2022/08/17 10:55:00 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = sources
OBJ_DIR = .objs

SRC =	$(SRC_DIR)/actions.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/forks.c \
		$(SRC_DIR)/philos.c \
		$(SRC_DIR)/threads.c \
		$(SRC_DIR)/time.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/routine.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[1;32mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[1;31mRemoving objects\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[1;31mRemoving philo\033[0m"

re: fclean all

.PONY: all clean fclean re