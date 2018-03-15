#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:48:48 by sflinois          #+#    #+#              #
#    Updated: 2018/03/11 16:51:40 by sflinois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

NAME = corewar

CFLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -fsanitize=address -fno-omit-frame-pointer
CC = gcc $(CFLAGS)

SRC_PATH = srcs/
SRC_NAME = main.c\
		   parsing.c\
		   pars_player.c\
		   flag_funct.c\
		   debug.c\
		   debug2.c\
		   exit.c\
		   op.c\
		   list_cpu.c\
		   arena.c\
		   arena2.c\
		   ncurses.c\
		   ncurses_2.c\
		   move_pc.c\
		   instructions/init_tab.c\
		   instructions/add.c\
		   instructions/aff.c\
		   instructions/and.c\
		   instructions/and_2.c\
		   instructions/conv.c\
		   instructions/conv2.c\
		   instructions/fork.c\
		   instructions/ld.c\
		   instructions/ldi.c\
		   instructions/ldi_2.c\
		   instructions/lfork.c\
		   instructions/live.c\
		   instructions/lld.c\
		   instructions/lldi.c\
		   instructions/lldi_2.c\
		   instructions/or.c\
		   instructions/or_2.c\
		   instructions/st.c\
		   instructions/sti.c\
		   instructions/sti_2.c\
		   instructions/sub.c\
		   instructions/xor.c\
		   instructions/xor_2.c\
		   instructions/zjmp.c

OBJ_PATH = objs/
INC_PATH = includes/

LIB_PATH = libft/
LIB = $(LIB_PATH)libft.a
LDFLAGS = -lncurses -L $(LIB_PATH) -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(LIB):
	@make all -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo $(CCGREEN) Corewar OK $(CCEND)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/instructions 2> /dev/null || true
	@$(CC) $(CFLAGS)  -o $@ -c $< -I $(LIB_PATH)$(INC_PATH) -I $(INC_PATH)
	@echo "$< ✓"

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH)/instructions 2> /dev/null || true
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
