# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 18:17:42 by aburdeni          #+#    #+#              #
#    Updated: 2018/10/27 18:17:45 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
LIBFT_DIR = ./libft/

HEADER = $(addprefix $(INC_DIR), ft_ssl.h)

SRC = main.c \
	ft_md5.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: 
	@rm -rf $(OBJ_DIR)
	@mkdir $(OBJ_DIR)
	@make $(NAME)
	@echo "\n\033[35mft_ssl\033[0m got $(NAME)"

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	@echo -n ' <@>'

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(INC_DIR)*.h.gch
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(NAME)
	@rm -rf test_me
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[35mft_ssl\033[0m was fcleaned"
