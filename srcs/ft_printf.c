/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:25 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	const char	*p;
	t_var		st;

	va_start(ap, fmt);
	p = fmt;
	st.space_count = 0;
	st.char_count = 0;
	while (*p)
	{
		if (*p != '%' && ++st.char_count)
		{
			ft_putchar(*p++);
			continue ;
		}
		p++;
		while (*p == ' ' && ++st.space_count && ++st.char_count)
			p++;
		if (st.space_count > 1)
			st.char_count -= st.space_count;
		st.char_count = check_ptr(&st, p, ap);
		if (!st.char_count)
			return (-1);
		p++;
		st.space_count = 0;
	}
	va_end(ap);
	return (st.char_count);
}





















/*
t_print		**init_dispatch_table(void)
{
	t_print	**table;

	if (!(table = malloc(sizeof(t_print *) * 13)))
		return (NULL);
	table[CHAR] = &print_char;
	table[STRING] = &print_string;
	table[POINTER] = &print_pointer;
	table[INT_D] = &print_int;
	table[INT_I] = &print_int;
	table[UNSIGNED_INT] = &print_unsigned;
	table[HEX_LC] = &print_hex;
	table[HEX_UC] = &print_hex;
	table[OCT] = &print_oct;
	table[PERCENTAGE] = &print_percentage;
	table[COUNT] = &print_count;
	table[DOUBLE] = &print_double;
	table[E_OR_F] = &print_e_or_f;
	table[SCIENCE] = &print_science;
	return (table);
}
*/