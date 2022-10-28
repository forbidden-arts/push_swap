# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2022/10/28 11:22:58 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c		\
		ft_bzero.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\

# SRCSB =	ft_lstnew.c			\
# 		ft_lstadd_front.c	\
# 		ft_lstsize.c		\
# 		ft_lstlast.c		\
# 		ft_lstadd_back.c	\
# 		ft_lstclear.c		\
# 		ft_lstdelone.c		\
# 		ft_lstiter.c		\
# 		ft_lstmap.c			\
# 		$(SRCS)

# Text Decoration Defs
bold := $(shell tput bold)
undln := $(shell tput smul)

black := $(shell tput setaf 0)
red := $(shell tput setaf 1)
green := $(shell tput setaf 2)
yellow := $(shell tput setaf 3)
blue := $(shell tput setaf 4)
magenta := $(shell tput setaf 5)
cyan := $(shell tput setaf 6)
white := $(shell tput setaf 7)
grey := $(shell tput setaf 8)
b_red := $(shell tput setaf 9)
b_green := $(shell tput setaf 10)
b_yellow := $(shell tput setaf 11)
b_blue := $(shell tput setaf 12)
b_magenta := $(shell tput setaf 13)
b_cyan := $(shell tput setaf 14)
b_white := $(shell tput setaf 15)

# https://upload.wikimedia.org/wikipedia/commons/1/15/Xterm_256color_chart.svg

reset := $(shell tput sgr0)
# End Def


NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	$(info $(b_green)Compiling:$(reset) $<)
	@cc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	$(info $(b_blue)$(bold)LIBFT COMPILED SUCCESSFULLY$(reset))

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_BONUS_PREFIXED)
	$(info $(b_magenta)$(bold)LIBFT COMPILED SUCCESSFULLY$(reset))
