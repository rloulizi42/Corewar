# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/30 18:29:54 by kkhalfao          #+#    #+#              #
#    Updated: 2018/03/10 16:55:11 by sflinois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =    "\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

SRC_PATH = src
SRC_NAME = ft_atoi.c \
		   ft_bzero.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isalpha.c \
		   ft_isprint.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memset.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdup.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnstr.c \
		   ft_strrchr.c \
		   ft_strstr.c \
		   ft_tolower.c \
		   ft_toupper.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strnew.c \
		   ft_strdel.c \
		   ft_strclr.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strsplit.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_putendl.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_itoa.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_strndup.c \
		   ft_strclen.c \
		   ft_strjoin_free.c \
		   get_next_line.c \
		   ft_copy_tab.c \
		   ft_create_tab_char.c \
			ft_strschr.c \
			ft_copy_tab_int.c \
			ft_bzero_int.c \
			ft_create_tab_int.c \
			ft_print_tab_int.c \
			file_for_fd.c \
			ft_print_tab.c


S_PRINTF_PATH = $(SRC_PATH)/src_printf
S_PRINTF_NAME = ft_convert.c \
				ft_printf.c \
				ft_fisrt_fonctin_d.c \
				ft_itoa_base.c \
				ft_load_printf.c \
				ft_option_c_c.c \
				ft_option_d_d.c \
				ft_option_justify.c \
				ft_option_o_o.c \
				ft_option_p.c \
				ft_option_printf.c \
				ft_option_s_c.c \
				ft_option_x_x.c \
				ft_order_flag_for_print.c \
				ft_order_presi.c \
				ft_tool_for_options.c \
				ft_tools_printf.c \
				ft_tools_wild_char.c \
				ft_utoa_base.c \
				ft_when_nb_is_zero.c \
				ft_option_s_long.c \
				ft_char_s_s_s.c \
				ft_special_o.c

OBJ_PATH = obj
CPPFLAGS = -Iincludes

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)
	O_PRINTF_NAME = $(S_PRINTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
S_PRINTF = $(addprefix $(S_PRINTF_PATH)/,$(S_PRINTF_NAME))
O_PRINTF = $(addprefix $(OBJ_PATH)/,$(O_PRINTF_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(O_PRINTF)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo $(CCGREEN) Libft.a OK $(CCEND)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o : $(S_PRINTF_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo $(CCRED)
	@rm -fv $(OBJ)
	@rm -fv $(O_PRINTF)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(O_PRINTF_PATH) 2> /dev/null || true
	@echo $(CCEND)

fclean: clean
	@echo $(CCRED)
	@rm -fv $(NAME)
	@echo $(CCEND)

re: fclean all

norme:
	norminette $(S_PRINTF)
	norminette $(SRC)
	norminette $(INC_PATH)*.h
