/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:17:09 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/05/17 14:08:08 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"

# define TO_ADD 	1
# define TO_RIGHT 	2
# define TO_CONVERT 4
# define TO_ESPACE 	8
# define TO_ZERO 	16
# define NO_FLAG	64

# define ERROR 		128

# define TO_H 		1
# define TO_HH 		2
# define TO_L		4
# define TO_LL 		8
# define TO_J 		16
# define TO_Z 		32

# define NO_CONVERT 64

# define TO_DOLLARS	1
# define TO_STARS_1	2
# define TO_STARS_2	4

typedef	struct		s_t1
{
	uintmax_t		nb;
	uintmax_t		ret;
	int				to_flag;
	int				field;
	int				zero_field_more;
	int				presi;
	int				stock_presi;
	int				convert;
	int				bonus;
	int				dollars;
	int				stars_field;
	int				stars_presi;
	int				value;
	int				error;
}					t_flag;

int					ft_printf(char *str, ...);
t_flag				*ft_init_flag(t_flag *stock);
int					ft_until_options(char *format, va_list ap);
void				ft_load_struct(char *format, t_flag **stock);
void				ft_load_options(char *format, t_flag **stock);
void				ft_load_field_min(char *format, t_flag **stock);
void				ft_pres(char *format, t_flag **stock);

void				ft_dollars(char *format, t_flag **stock);
int					ft_flag_stars_presi(char *format, t_flag **stock);
int					ft_flag_stars_field(char *format, t_flag **stock);

int					ft_putwchar(wchar_t chr);
int					ft_putwstr(wchar_t *str, t_flag **stock);
int					ft_strwlen(wchar_t *str);
int					ft_wchar_len(wchar_t x);

intmax_t			ft_search_convert_d(t_flag **stock, va_list ap);
uintmax_t			ft_search_convert_d_d_d_d(t_flag **stock, va_list ap);

void				ft_convert(char *format, t_flag **stock, va_list ap);
void				ft_convert_1\
						(char *format, t_flag **stock, va_list ap, int i);
void				ft_option_convert(char *format, t_flag **stock);

void				ft_char_c(t_flag **stock, va_list ap);
void				ft_char_c_c(char *format, t_flag **stock, va_list ap);
void				ft_char_s(t_flag **stock, va_list ap);
void				ft_char_s_s(t_flag **stock, va_list ap);
void				ft_1(int print_presi, t_flag **stock, char *c, int i);
int					ft_count_pres(t_flag **stock, char *str, int print_presi);
void				ft_option_d(t_flag **stock, va_list ap);
void				ft_option_d_d(t_flag **stock, va_list ap);
void				ft_option_x(t_flag **stock, va_list ap, char *format);
void				ft_option_o(t_flag **stock, va_list ap, char *format);
void				ft_option_p(t_flag **stock, va_list ap);
void				ft_print_percent(t_flag **stock);

char				*ft_str_upper(char *tmp);
int					ft_search_flag_for_conver(t_flag **stock, \
					char *format, int x);
void				ft_char_spe(char *format, t_flag **stock, va_list ap);
void				ft_str_null(t_flag **stock);

void				ft_print_percent(t_flag **stock);
char				*ft_itoa_base(intmax_t nb, int base);
char				*ft_utoa_base(uintmax_t nb, int base);
int					ft_len_number(intmax_t a, int base);
int					ft_len_u_number(uintmax_t a, int base);
unsigned long long	ft_len_u_number_p(unsigned long long a, int base);

void				ft_print_zero_test(intmax_t i, t_flag **stock);
void				ft_print_zero(intmax_t i, t_flag **stock);
void				ft_print_space(intmax_t i, t_flag **stock);
void				ft_print_if_neg(intmax_t x, t_flag **stock);
void				test_flag_zero(int a, int i);

char				*ft_if_nb_is_zero\
						(int nb_len, t_flag **stock, int base, intmax_t x);
int					ft_print_flag_add_minus(t_flag **stock, intmax_t x);
void				ft_order_all_flag\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);
void				ft_order_with_presi\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);
void				ft_order_field_m_p\
						(t_flag **stock, int to_print, intmax_t x, int sous);
void				ft_print_sous_if_presi_neg\
						(int sous, intmax_t x, t_flag **stock);
void				ft_order_for_print_space\
						(t_flag **stock, int to_print, intmax_t x, int sous);
void				ft_order_print_space_plus\
						(t_flag **stock, int to_print, intmax_t x, int sous);
void				ft_order_print_space_neg\
						(t_flag **stock, int to_print, intmax_t x, int sous);
int					ft_check_if_flag(t_flag **stock, intmax_t x);

char				*ft_flag_zero\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);
char				*ft_flag_to_zero\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);
int					ft_flag_to_print\
						(t_flag **stock, int to_print, intmax_t x);
char				*ft_flag_to_zero_tmp\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);

void				ft_pri_jus_fi_prs\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);
void				ft_p_jus_ony_prs\
						(t_flag **stock, int to_print, char *tmp, intmax_t x);

void				ft_print_struct(t_flag *st);
void				ft_print_space_test(intmax_t i, t_flag **stock);

int					ft_enlev_sig(t_flag **stock);
char				*ft_search_flag_for_flag_convert(t_flag **stock, char *tmp);

int					ft_count_pres(t_flag **stock, char *str, int print_presi);
int					ft_print_flag_add_minus_2(t_flag **stock, intmax_t x);

char				*ft_replace_zerot_(t_flag **stock, char *tmp, int nb_zero);
int					ft_search_zero_for_convert\
						(t_flag **stock, char *tmp, int nb_zero);

int					ft_count_pres_long\
						(t_flag **stock, wchar_t *str, int print_presi);
void				ft_char_s_long(t_flag **stock, wchar_t *c);

char				*ft_special_option_o(t_flag **stock);
char				*ft_tmp_zero(void);
char				*ft_tmp_b_zero(void);
void				ft_str_null(t_flag **stock);
int					ft_count_pres_long\
						(t_flag **stock, wchar_t *str, int print_presi);
char				*ft_if_nb_zero_5(char *tmp, t_flag **stock);
#endif
