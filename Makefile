# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2022/12/20 06:55:29 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		=	push_swap
NAMELIB		=	push_swap.a
INCLUDE		=	-I include
LIBFT		=	libft
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

#Sources

SRC_FILES	=	push_swap	\
				stack_utils	\
				build_stack	\
				utils


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@mv $(LIBFT)/libft.a ./libft.a
			@mv libft.a $(NAMELIB)
			@$(AR) $(NAMELIB) $(OBJ)
			@$(CC) $(CFLAGS) $(INCLUDE) $(NAMELIB) -o push_swap
			@echo "$(B_MAGENTA)PUSH_SWAP COMPILED SUCCESSFULLY\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)OBJECT FILES DELETED$(C_RESET)"

fclean:		clean
			@rm -f $(NAME) $(NAMELIB)
			@echo "$(CYAN)EXECUTABLE FILES DELETED$(C_RESET)"
#			@rm -f $(NAMELIB)
#			@echo "$(CYAN)LIBFT LIBRARY DELETED$(C_RESET)"

re:			fclean all
