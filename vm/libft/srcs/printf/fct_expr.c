/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_expr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:45:51 by sflinois          #+#    #+#             */
/*   Updated: 2018/01/20 14:52:25 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		new_expr(t_expr *expr)
{
	expr->flags = 0;
	expr->min_width = 0;
	expr->precision = -1;
	expr->length = 0;
	expr->type = 0;
}
