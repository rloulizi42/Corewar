/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:23:44 by kkhalfao          #+#    #+#             */
/*   Updated: 2018/03/11 17:31:12 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define SEPARATOR_CHAR          ','

# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"

# define REG_NUMBER              16

# define NBR_LIVE                21
# define CYCLE_TO_DIE            1536
# define CYCLE_DELTA             50
# define MAX_CHECKS              10

typedef unsigned char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH   (128)
# define COMMENT_LENGTH     (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

#endif
