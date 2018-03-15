/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:45:51 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/14 15:16:58 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../includes/libft.h"
# include "../includes/get_next_line.h"
# include "../includes/ft_printf.h"
# include "../includes/op.h"
# include "../includes/parsing.h"

# define PARSE_NAME 		2
# define NAME_OK 			4
# define PARSE_COMMENT 		8
# define COMMENT_OK 		16
# define NAME_COMMENT_END 	32
# define MANY_LINES			1
# define ONLY_ONE_LINES		2
# define CASE_NAME			1
# define CASE_COMMENT		2

typedef	struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

/*
**==================================================================
**valeur de ref pour savoir ou on est dans le GNL
**==================================================================
*/

typedef	struct		s_refvalue
{
	int				name;
	int				len_string_name;
	int				nb_quote;
	int				macro;
}					t_refvalue;

/*
**==================================================================
**					Structure principale
**-ref  -> ou on est dans le GNL -> si comment ou name et si fini
**  	   pour commencer le pars du texte
**-head -> la strucure de base pour stocker les noms et comentaires
**==================================================================
*/

typedef	struct		s_struct
{
	t_header		head;
	t_refvalue		ref;
	int				stock_name;
	int				stock_comment;
	int				fd;
	char			*string;
	int				back_n;
}					t_asm;

/*
**==================================================================
** Contient la structure qui sert a parser les commentaires et name
**==================================================================
*/

typedef	struct		s_tab
{
	char			*comment;
	int				(*f)(char *line, t_asm *tmp, int ref);
	int				i;
}					t_get;

/*
**==================================================================
**						init_struct
**==================================================================
*/

t_asm				init_strcut_header(void);

/*
**==================================================================
**						Le fichier
**==================================================================
*/

int					lot_of_files(char *argv);
int					get_fd_and_line(char *line, t_asm *tmp, t_lst_asm **list);
int					check_open_file(char *argv);
int					check_name(char *line);
void				fill_nb_dir_arg(t_lst_asm **lst, int ref);
void				get_nb_dir(t_lst_asm **lst, long long int stock, int ref);
void				free_list(t_lst_asm **lst);
int					ft_inbase(char c, int base);
void				get_nb_pos_label(t_lst_asm **lst, int nb, int ref);
int					check_first_char(char *gnl);
int					after_while(char *str, int i);
int					get_comment(char *line, t_asm *tmp, int ref);
int					get_name(char *line, t_asm *tmp, int ref);

/*
**==================================================================
**						Parsing
**==================================================================
*/

int					parsing_name_comment(char *line, t_asm *tmp);
int					write_ocp(char **tmp, int i, t_lst_asm **lst);
void				write_one_arg(char **tmp, int ref, t_lst_asm **lst);
void				write_all_arg(char **tmp, int fd, t_lst_asm **lst, int ref);
int					fill_header(char **tmp, t_lst_asm **lst, t_asm *header,
					int fd);
int					is_space_tab(char c);
int					find_no_label(t_lst_asm **lst, t_lst_asm *search, int ref);
int					find_label(t_lst_asm **lst, t_lst_asm *search);
int					check_if_upcode_after_label(int i, char *line);
void				fill_tmp(char *tmp, int *i);
void				check_after_name(char *line, int ref);
int					is_no_char_begin_label(char *line, t_lst_asm **lst, int *i);
void				fill_reg(int stock, t_lst_asm **lst, int ref);
void				fill_list_value(t_lst_asm **lst, int ref);
int					check_char_args(char *line, int *i, int *x, char **tmp);
void				put_space_string(char *line, int *x, char **tmp);
int					join_before_acually(char **line, char *label,
					t_lst_asm **lst);
int					pars_first_line_name(char *line, int rf);
int					copy_one_line(char *line, t_asm *tmp, int ref, int macro);
void				check_lenght_name(char *line, int len_max);
void				continue_init_struct(t_lst_asm **lst);
int					copy_not_only_one_string(char *line, t_asm *tmp, int ref);
int					copy_other_string(char *line, \
		t_asm *tmp, int ref, int macro);
void				check_after_quote(char *line, int quote, int x);
void				where_we_are_in_parsing_name_comment(t_asm *tmp\
		, int macro, int ref);
int					len_name(char *line, int rf, int pos_sec_quot);

int					write_file(char *argv, t_lst_asm **lst, t_asm *header);
/*
**==================================================================
**						Tools
**==================================================================
*/

void				ft_exit(int i, char *line);
int					ft_str_is(char *line, char c);
int					ft_strrschr(char *s1, char *s2);
int					first(char *line, int ref);
int					ft_strrclen(char *s1, char *s2);
void				ft_freeall(t_lst_asm **lst);

#endif
