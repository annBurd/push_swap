# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 18:17:42 by aburdeni          #+#    #+#              #
#    Updated: 2018/11/11 19:34:27 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECK = checker
NAME_PS = push_swap



CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

HEADER = $(wildcard $(INC_DIR)*.h)

SRC = checker.c \
	command_a.c \
	command_b.c \
	command.c \
	validation.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIBFT_DIR)
	@echo "start compilation & release alien spaceships""\033[2;35m"
	@make $(NAME_CHECK)

$(NAME_CHECK): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_CHECK) $(OBJ) $(LIBFT)
	@echo "\n\033[0mgot ""\033[2;36m""$(NAME_CHECK)\033[0m binary"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n ' <@>'

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(INC_DIR)*.h.gch
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(NAME_CHECK)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[2;36m""push_swap""\033[0m"" was fcleaned"

re: fclean all

.PHONY: all clean fclean re checker
	