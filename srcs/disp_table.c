/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 10:02:20 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_fptr_print_op disp_table[16] = {NULL};

void	initializing_disp_table()
{
	disp_table[INT] = int_print;
	disp_table[DEC] = int_print;
	disp_table[CHAR] = char_print;
	disp_table[STR] = str_print;
	disp_table[UINT] = uint_print;
};

/*
** //more cases comming
*/

int	check_ptr(t_var *st, const char	*p, va_list	ap)
{
	int		i;

	i = 0;
	initializing_disp_table();
	while (TABLE_POS[i] && TABLE_POS[i] != *p)
		i++;
	if (*p == '\n' && ++st->char_count)
		ft_putchar('\n');
	else if (*p == '%' && ++st->char_count)
		ft_putchar('%');
	else if (TABLE_POS[i] == '\0')
		return (0);
	else
		st->char_count = disp_table[i](st, p, ap);
	return (st->char_count);
}