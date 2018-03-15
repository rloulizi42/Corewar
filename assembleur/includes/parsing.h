/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:03:05 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/14 15:12:37 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define LABEL			0
# define PARAMS_1		1
# define PARAMS_2 		2
# define PARAMS_3 		3

# define TRUE	 		1
# define FALSE	 		0

# define DIEZ	  		"#"
# define REG	  		"r"
# define DIR_LABEL 		"%:"
# define DIR_NB	  		"%"
# define IND_LABEL 		":"
# define IND_NB    		"0123456789+-"

# define ONLY_LABEL	  	1
# define LABEL_INSTRUC 	2
# define INSTRUC	  	4

# define LIVE		  	0
# define ZJUMP		  	6
# define FORK		  	10
# define LFORK		  	14

/*
** structures
*/

typedef struct		s_op
{
	char			*label;
	int				nb_param;
	unsigned int	param[3];
	int				opcode;
	int				nb_cycle;
	char			*comment;
	int				mod_carry;
	int				size_dir;
	int				len_cmp;
}					t_op;

extern t_op			g_op_tab[17];

/*
** structure principale qui contiendra tout ce qu'il faut
*/

typedef	struct		s_param
{
	int				chr;

	int				if_no_params;
	int				ocp_param;

	char			*label;

	char			ins[10];
	char			stock[9];

	long long int	nb;
	int				reg;
}					t_params;

/*
**	structure principale qui contiendra tout ce qu'il faut
*/
typedef	struct		s_asm
{
	char			*line;
	int				tab;

	int				label_instruc;

	int				pos_label;
	int				pos_idx;
	int				index;

	t_arg_type		ocp;
	int				no_ocp;

	int				nb_final;
	int				nb;

	t_params		p[3];

	int				fd;
	int				i;

	struct s_asm	*next;
	struct s_asm	*prev;

}					t_lst_asm;

/*
** tableau de fonction qui servira savoir si c indirect, registre ou directe
*/
typedef	struct		s_params
{
	char			*params;
	int				(*f)(int i, char *line, t_lst_asm **lst, int ref);
	int				nb_param_to_check;
}					t_param;

/*
** creation de la liste et fonctions associes
*/

t_lst_asm			*create_t_lst(char *line);
void				create_list_asm(char *line, t_lst_asm **list);
void				ft_lstaddback_2(t_lst_asm **lst, t_lst_asm *new);
void				print_list_asm(t_lst_asm **list);
void				print_list_prev_asm(t_lst_asm **list);

char				*split_line(char *line);
char				*copy_string_witout_space_tab(char *tmp, char *line);

int					parse_check_if_label(char *line, int *x, \
					int *i, char **tmp);
int					parse_check_upcode(char *line, int *i, int *x, char **tmp);
int					pars_check_arg(char *line, int *i, int *x, char **tmp);
int					check_separator_neg(char *line, int *i, int *x, char **tmp);
int					check_separator(char *line, int *i, int *x, char **tmp);

/*
** ecriture
** ////////////////////////////////////////////////////////////////////////////
*/

int					len_to_create(char *line);
int					create_file(char *line);
void				get_ocp(t_lst_asm **lst, int nb_param, int ocp);

void				get_label_jump(t_lst_asm **lst, \
					t_lst_asm **search, int ref);

int					write_exe_code(char **tmp, int i, int fd);
int					write_prog_name(char **tmp, int fd, char *name, int len);
int					write_null(char **tmp, int i, int fd);
int					write_nb_arg(char **tmp, int i, int fd, t_lst_asm **lst);
int					write_upcode(char **tmp, int i, t_lst_asm **lst);

/*
** parsing du label, upcode et parametres
** ////////////////////////////////////////////////////////////////////////////
*/

int					tokenizer(t_lst_asm **list);
int					create_token(char *line, t_lst_asm **lst);
int					is_begin_by_label(char *line, t_lst_asm **lst);
int					what_upcode_is(int i, char *line, t_lst_asm **lst);
int					check_params(int i, char *line, t_lst_asm **lst);
int					parsing_params(int i, char *line, t_lst_asm **lst, int ref);

int					f_reg(int i, char *line, t_lst_asm **lst, int ref);
int					f_label_dir(int i, char *line, t_lst_asm **lst, int ref);
int					f_nb_dir(int i, char *line, t_lst_asm **lst, int ref);
int					f_label_indir(int i, char *line, t_lst_asm **lst, int ref);
int					f_nb_indir(int i, char *line, t_lst_asm **lst, int ref);

void				p_label(int ref, t_lst_asm **lst, \
					t_lst_asm *search, t_lst_asm *tmp);
void				put_pos_label_index(t_lst_asm **lst, t_lst_asm *tmp);

/*
** analyse en comparant les upcode obtenues
** ////////////////////////////////////////////////////////////////////////////
*/

int					analysis(t_lst_asm **lst);

/*
** tools
** ////////////////////////////////////////////////////////////////////////////
*/
int					after_space(char *line, int i);
int					check_separator_char(char *line, int i, char ref);
char				*ft_strcclen(char *line, int c, int ref);
int					ft_strnblen(char *line, int c, int ref);
int					if_is_label_chars(char line);
int					ft_striflen(const char *str, char c);
int					ft_strnncmp(const char *str, char *cmp, int nb_to_check);
int					exit_file(char *line);
void				print_all_params(t_lst_asm **lst);
int					ft_strxcmp(const char *s1, const char *s2, int n);
int					ft_atoi_base(char *str, int base);

long long int		ft_atoi_lld(const char *str);
int					is_space_tab(char c);
int					after_space(char *line, int i);
int					is_arg(char c);

int					exit_file(char *line);
int					check_name(char *line);
int					check_open_file(char *argv);
int					check_separator(char *line, int *i, int *x, char **tmp);
int					check_separator_neg(char *line, int *i, int *x, char **tmp);
int					check_and_fill_arg(char *line, int i);

void				print_all_params(t_lst_asm **lst);
void				init_struct_params(int nb, t_lst_asm **lst);
int					put_b_zero(char **tmp, char *line, int *i, int *x);
void				check_if_more_arg(char *line, int i);
void				fill_y(t_lst_asm **lst, int ref, int y);
int					check_if_zero(char *line, int *i, int *x, char **tmp);
int					continue_check_label(char *line, int *i, \
		int *x, char **tmp);
void				check_diez(char *line, int i);
void				check_after_before_quote(char *line, int j, int ref);
void				check_if_no_point(char *line, int *j);
void				fill_b_space(char **line, int *i, int len_max);
void				check_len(char *str, int ref);
#endif
