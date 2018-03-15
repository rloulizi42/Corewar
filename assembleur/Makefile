#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:48:48 by sflinois          #+#    #+#              #
#    Updated: 2018/03/14 15:02:18 by rloulizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

NAME = asm

CFLAGS = -Wall -Wextra -Werror -g
CC = gcc $(CFLAGS)

SRC_PATH = src/
SRC_NAME = init_t_lst.c \
		   fonction_check_params_r_dir.c \
		   get_file.c \
		   tool_init_struct.c \
		   tools_pars_arg.c \
		   analysis_params_get.c \
		   ft_atoi_base.c \
		   get_pos_label_jump.c \
		   parse_content_name_comment.c \
		   tools_chech_begin.c \
		   write_file.c \
		   asm.c \
		   ft_free_all.c \
		   op.c \
		   token_p2.c \
		   tools_fonctions.c \
		   write_header.c \
		   create_file.c \
		   ft_split_lane.c \
		   pars_name.c \
		   token_pars_label_upcode.c \
		   tools_list.c \
		   fonction_check_indir.c \
		   ft_split_lane_2.c \
		   pars_name_2.c \
		   tokenizer.c \
		   tools_name_comment.c \

OBJ_PATH = objs/
INC_PATH = includes/

LIB_PATH = libft/
LIB = $(LIB_PATH)libft.a
LDFLAGS = -L $(LIB_PATH) -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(LIB):
	@make all -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $@
	@echo $(CCGREEN) asm OK $(CCEND)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
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
