/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:48:18 by ajehanno          #+#    #+#             */
/*   Updated: 2018/03/07 20:17:33 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <curses.h>
# include <locale.h>

typedef struct			s_op
{
	char				*name;
	int					nb_param;
	unsigned int		param[3];
	int					opcode;
	int					nb_cycle;
	char				*comment;
	int					mod_carry;
	int					size_dir;
}						t_op;

t_op					g_op_tab[17];

typedef struct			s_list_cpu
{
	unsigned char		reg[REG_SIZE * REG_NUMBER];
	int					pc;
	int					live;
	char				carry;
	int					wait;
	char				opcode;
	int					nb_param;
	char				ocp;
	struct s_list_cpu	*prev;
	struct s_list_cpu	*next;
}						t_list_cpu;

typedef struct			s_vm
{
	int					nb_champs;
	int					num_champs[4];
	int					next_num;
	int					live_by_champs[4];
	t_header			*data_champs[4];
	char				*inst_champs[4];
	t_list_cpu			*cpu_list;
	t_list_cpu			*last_cpu;
	unsigned int		dump;
	int					verbose;
	int					viewer;
	unsigned char		arena[MEM_SIZE];
	char				property[MEM_SIZE];
	int					cycle;
	int					cycle_check;
	int					cycle_to_die;
	int					nbr_live_cycle_to_die;
	int					count_checks;
	int					live;
	int					run;
	int					speed_run;
	char				status_run[20];
	WINDOW				*win;
	int					nb_cpu;
}						t_vm;

typedef struct			s_params
{
	char				*pars;
	int					(*fct_pars)(char **av, int i_av, int ac, t_vm *vm);
	int					nb_param;
}						t_params;

typedef void			(*t_inst)(t_vm *vm, t_list_cpu *cpu);

/*
** ////////////////////////////////////////////////////////////////////////////
** DEBUG
** ////////////////////////////////////////////////////////////////////////////
*/

void					ft_print_data_champs(t_vm *vm, int index_champ);
void					ft_print_inst_champs(t_vm *vm, int index_champ);
void					ft_print_champs(t_vm *vm);
void					ft_put_arena(t_vm *vm);
void					ft_print_cpu(t_list_cpu *cpu);
void					ft_print_cpulist(t_vm *vm);
void					ft_show_move_pc(t_vm *vm, t_list_cpu *cpu, int drop);
void					display_contestants(t_vm *vm);
void					display_winner(t_vm *vm);

/*
** ////////////////////////////////////////////////////////////////////////////
** EXIT
** ////////////////////////////////////////////////////////////////////////////
*/

void					ft_exit_usage_vm(void);

/*
** ////////////////////////////////////////////////////////////////////////////
** PARSING
** ////////////////////////////////////////////////////////////////////////////
*/

int						pars_args(int argc, char **argv, t_vm *vm);
int						set_champ_num(char **av, int i_av, int ac, t_vm *vm);
int						set_dump_param(char **av, int i_av, int ac, t_vm *vm);
int						set_verb_param(char **av, int i_av, int ac, t_vm *vm);
int						set_viewer_param(char **av, int i_av, int ac, t_vm *vm);
int						set_player_number(int num, t_vm *vm);
int						add_player(char **av, int i_av, int num, t_vm *vm);
unsigned int			little_to_big_endian(unsigned int i);

/*
** ////////////////////////////////////////////////////////////////////////////
** CPU_LIST
** ////////////////////////////////////////////////////////////////////////////
*/

void					create_cpu(t_vm *vm, int i);
void					add_new_cpu(t_vm *vm, t_list_cpu *parent, int pc);
void					del_cpu(t_vm *vm, t_list_cpu *cpu);

/*
** ////////////////////////////////////////////////////////////////////////////
** RUN COREWAR
** ////////////////////////////////////////////////////////////////////////////
*/

int						run_corewar(t_vm *vm);
void					exec_cycle(t_vm *vm);

/*
** ////////////////////////////////////////////////////////////////////////////
** FIGHT
** ////////////////////////////////////////////////////////////////////////////
*/

void					init_tab(void);

typedef void			(*t_ld)(t_vm *vm, t_list_cpu *cpu);
t_ld					g_ld[256];
void					ft_ld_ir(t_vm *vm, t_list_cpu *cpu);
void					ft_ld_dr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_lld)(t_vm *vm, t_list_cpu *cpu);
t_lld					g_lld[256];
void					ft_lld_ir(t_vm *vm, t_list_cpu *cpu);
void					ft_lld_dr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_st)(t_vm *vm, t_list_cpu *cpu, int nb);
t_st					g_st[256];
void					ft_st_r(t_vm *vm, t_list_cpu *cpu, int nb);
void					ft_st_i(t_vm *vm, t_list_cpu *cpu, int nb);
void					ft_st_invalid(t_vm *vm, t_list_cpu *cpu, int nb);

typedef void			(*t_and)(t_vm *vm, t_list_cpu *cpu);
t_and					g_and[256];
void					ft_and_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_and_irr(t_vm *vm, t_list_cpu *cpu);
void					ft_and_drr(t_vm *vm, t_list_cpu *cpu);
void					ft_and_rir(t_vm *vm, t_list_cpu *cpu);
void					ft_and_iir(t_vm *vm, t_list_cpu *cpu);
void					ft_and_dir(t_vm *vm, t_list_cpu *cpu);
void					ft_and_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_and_idr(t_vm *vm, t_list_cpu *cpu);
void					ft_and_ddr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_or)(t_vm *vm, t_list_cpu *cpu);
t_or					g_or[256];
void					ft_or_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_or_irr(t_vm *vm, t_list_cpu *cpu);
void					ft_or_drr(t_vm *vm, t_list_cpu *cpu);
void					ft_or_rir(t_vm *vm, t_list_cpu *cpu);
void					ft_or_iir(t_vm *vm, t_list_cpu *cpu);
void					ft_or_dir(t_vm *vm, t_list_cpu *cpu);
void					ft_or_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_or_idr(t_vm *vm, t_list_cpu *cpu);
void					ft_or_ddr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_xor)(t_vm *vm, t_list_cpu *cpu);
t_xor					g_xor[256];
void					ft_xor_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_irr(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_drr(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_rir(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_iir(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_dir(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_idr(t_vm *vm, t_list_cpu *cpu);
void					ft_xor_ddr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_ldi)(t_vm *vm, t_list_cpu *cpu);
t_ldi					g_ldi[256];
void					ft_ldi_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_ldi_irr(t_vm *vm, t_list_cpu *cpu);
void					ft_ldi_drr(t_vm *vm, t_list_cpu *cpu);
void					ft_ldi_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_ldi_idr(t_vm *vm, t_list_cpu *cpu);
void					ft_ldi_ddr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_lldi)(t_vm *vm, t_list_cpu *cpu);
t_lldi					g_lldi[256];
void					ft_lldi_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_lldi_irr(t_vm *vm, t_list_cpu *cpu);
void					ft_lldi_drr(t_vm *vm, t_list_cpu *cpu);
void					ft_lldi_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_lldi_idr(t_vm *vm, t_list_cpu *cpu);
void					ft_lldi_ddr(t_vm *vm, t_list_cpu *cpu);

typedef void			(*t_sti)(t_vm *vm, t_list_cpu *cpu);
t_sti					g_sti[256];
void					ft_sti_rrr(t_vm *vm, t_list_cpu *cpu);
void					ft_sti_rdr(t_vm *vm, t_list_cpu *cpu);
void					ft_sti_rir(t_vm *vm, t_list_cpu *cpu);
void					ft_sti_rrd(t_vm *vm, t_list_cpu *cpu);
void					ft_sti_rdd(t_vm *vm, t_list_cpu *cpu);
void					ft_sti_rid(t_vm *vm, t_list_cpu *cpu);

/*
** ////////////////////////////////////////////////////////////////////////////
** CYCLE
** ////////////////////////////////////////////////////////////////////////////
*/

void					ft_move_pc(t_vm *vm, t_list_cpu *data);

/*
** ////////////////////////////////////////////////////////////////////////////
** EXECUTION PROCESS
** ////////////////////////////////////////////////////////////////////////////
*/

int						indirect(t_vm *vm, t_list_cpu *cpu, int i);
int						indirect_var(t_vm *vm, t_list_cpu *cpu, int i);
int						direct_2(t_vm *vm, t_list_cpu *cpu, int i);
int						direct_4(t_vm *vm, t_list_cpu *cpu, int i);
void					report_property(t_vm *vm, t_list_cpu *cpu, int index,
						int len);
int						regtonb(t_list_cpu *cpu, int reg);
void					nbtoreg(t_list_cpu *cpu, int reg, int nb);

void					ft_live(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_ld(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_st(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_add(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_sub(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_and(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_or(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_xor(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_zjmp(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_ldi(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_sti(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_fork(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_lld(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_lldi(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_lfork(t_vm *vm, t_list_cpu *cpu_cpu);
void					ft_aff(t_vm *vm, t_list_cpu *cpu_cpu);

/*
** ////////////////////////////////////////////////////////////////////////////
** NCURSES
** ////////////////////////////////////////////////////////////////////////////
*/

void					ft_ncurses(t_vm *vm);
void					ft_ncurses_print_arena(t_vm *vm, int c);
void					ft_ncurses_print_info(t_vm *vm, int c);
void					ft_ncurses_print_info_2(t_vm *vm, int c);
void					ft_ncurses_init_cpu(t_vm *vm, int i);
int						ft_ncurses_wait(t_vm *vm);
int						ft_ncurses_wait_no_run(t_vm *vm);
void					ft_ncurses_print_cpu(t_vm *vm);
void					ft_ncurses_print_live(t_vm *vm);

#endif
