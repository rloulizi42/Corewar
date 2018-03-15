# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:48:48 by sflinois          #+#    #+#              #
#    Updated: 2018/03/11 14:57:29 by sflinois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

NAME = corewar asm


all: $(NAME)

$(NAME):
	@make -C vm
	@make -C assembleur
	@cp assembleur/asm .
	@cp vm/corewar .
	@echo $(CCGREEN) Corewar OK $(CCEND)

clean:
	@make clean -C vm
	@make clean -C assembleur

fclean: clean
	@make fclean -C vm
	@make fclean -C assembleur
	@rm -f asm
	@rm -f corewar

re: fclean all
