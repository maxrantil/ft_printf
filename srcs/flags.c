/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:54:14 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int flag_plus(t_var *st)
{
	if (*st->ptr == '+')
	{
		st->flag = ON;
		st->ptr++;
		return (check_parser(st));
	}
	return (0);
}

int	procentage_print(t_var *st)
{
	ft_putchar(*st->ptr);
	return (st->char_count);
}
