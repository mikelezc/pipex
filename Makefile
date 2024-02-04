# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:30:58 by mlezcano          #+#    #+#              #
#    Updated: 2024/02/04 12:27:15 by mlezcano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

#compiler

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f
ECHO		= echo -e

#output
NAME		= pipex

#directories
SRC_DIR		= src/
OBJ_DIR		= obj/

#include
INC			= inc
BNAME		= checker
HEADER		= -I inc
LIBFT		= libft


FSANITIZE	= -fsanitize=address -g3

#colors
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#src directories
PIP_DIR		=	pipex/
BONUS_DIR	=	bonus/

#src files
PIP_FILES	=	pipex utils
BONUS_FILES	=	

SRC_FILES	=	$(addprefix $(PIP_DIR), $(PIP_FILES))
SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

COMMON 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(COM_FILES)))
COBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(COM_FILES)))

BSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

OBJF		=	.cache_exists

start:
			@$(ECHO) -n "$(GREEN)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(WHITE)[$(DEF_COLOR)"
			@make all

all:		$(NAME)

$(NAME):	$(OBJ) $(COBJ) $(OBJF)
			@$(ECHO) -n "$(WHITE)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => OK! 🎉​$(DEF_COLOR)\n"
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@$(ECHO) -n "$(GREEN)[$(NAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ) $(COBJ) $(HEADER) libft.a -o $(NAME)
			@$(ECHO) "$(GREEN) => OK! 🎉​$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(ECHO) -n "$(DEF_COLOR)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(PIP_DIR)
			@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@$(ECHO) -n "$(RED)[push_swap]:\tobject files$(DEF_COLOR)$(YELLOW)  => Clean! 🚽$(DEF_COLOR)\n"
			@$(RM) $(OBJF)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@rm -rf *.dSYM
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "$(RED)[LIBFT]:\texec. files$(DEF_COLOR)$(YELLOW)  => Clean! 🚽$(DEF_COLOR)\n"
			@$(ECHO) -n "$(RED)[push_swap]:\texec. files$(DEF_COLOR)$(YELLOW)  => Clean! 🚽$(DEF_COLOR)\n"


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [push_swap]!🙌🙌🙌$(DEF_COLOR)\n"

			bonus:
			@$(ECHO) -n "$(YELLOW)[Dependencies]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make allbonus

allbonus:		$(BNAME)

$(BNAME):	$(BOBJ) $(COBJ)
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) -n "$(GREEN) => OK! 🎉$(DEF_COLOR)\n"
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@$(ECHO) -n "$(YELLOW)[$(BNAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(BSRC) $(COMMON) $(HEADER) libft.a -o $(BNAME)
			@$(ECHO) "$(GREEN) => OK! 🎉$(DEF_COLOR)"

.PHONY:		all clean fclean re
