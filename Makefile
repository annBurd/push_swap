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

NAME_CH = checker
NAME_PS = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

HEADER = $(wildcard $(INC_DIR)*.h)

SRC = command.c \
	command_a.c \
	command_b.c \
	validation.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_CH = $(addprefix $(OBJ_DIR), $(NAME_CH).o)
OBJ_PS = $(addprefix $(OBJ_DIR), $(NAME_PS).o)
OBJ_ALL = $(OBJ) $(OBJ_CH) $(OBJ_PS)

RESET = \033[0m
PURPLE = \033[2;35m
DIMCYAN = \033[2;36m

all:
	@mkdir -p $(OBJ_DIR)
	@echo "$(RESET)start compilation"
	@make -C $(LIBFT_DIR)
	@echo "release alien spaceships from $(DIMCYAN)$(NAME_PS)/$(PURPLE)"
	@make compile

compile: $(OBJ_ALL)
	@echo "$(RESET)"
	@make $(NAME_CH)
	@make $(NAME_PS)

$(NAME_CH):
	@$(CC) $(CFLAGS) -o $(NAME_CH) $(OBJ) $(OBJ_CH) $(LIBFT)
	@echo "got $(DIMCYAN)$(NAME_CH)$(RESET) binary"

$(NAME_PS):
	@$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJ) $(OBJ_PS) $(LIBFT)
	@echo "got $(DIMCYAN)$(NAME_PS)$(RESET) binary"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n '  <@>'

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(INC_DIR)*.h.gch
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(NAME_CH)
	@rm -rf $(NAME_PS)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(DIMCYAN)push_swap/$(RESET) was fcleaned"

re: fclean all

.PHONY: all clean fclean re checker push_swap
