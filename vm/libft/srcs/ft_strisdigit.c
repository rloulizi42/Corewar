/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:32:22 by sflinois          #+#    #+#             */
/*   Updated: 2018/03/14 10:50:16 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	while (str && *str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}
