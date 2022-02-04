/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/04 11:59:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	int_print(t_var st, const char *p, va_list ap)
{
	if (*p == 'd' || *p == 'i')
	{
		if (st.count-- && st.char_counter++)
			ft_putchar(' ');
		ft_putnbr(va_arg(ap, int));
		return (++st.char_counter);
	}
	return (st.char_counter);
}

int	char_print(t_var st, const char *p, va_list ap)
{
	if (*p == 'c' && ++st.char_counter)
	{
		ft_putchar(va_arg(ap, int));
		return (st.char_counter);
	}
	return (st.char_counter);
}

int	str_print(t_var st, const char *p, va_list ap)
{
	char	*str;

	if (*p == 's')
	{
		str = va_arg(ap, char *);
		while (*str && ++st.char_counter)
			ft_putchar(*str++);
		return (st.char_counter);
	}
	return (st.char_counter);
}

/*
** //more cases comming with %% and more
*/

/* int	check_ptr(t_var st, const char	*p, va_list	ap)
{
	st.char_counter = int_print(st, p, ap);
	st.char_counter = char_print(st, p, ap);
	st.char_counter = str_print(st, p, ap);
	if (*p == '\n' && ++st.char_counter)
		ft_putchar('\n');
	else if (*p == '%' && ++st.char_counter)
		ft_putchar('%');
	return (st.char_counter);
} */

int	check_ptr(t_var st, const char	*p, va_list	ap)
{	
	if (*p == 'd' || *p == 'i')
		st.char_counter = dispatch_table[0](st, p, ap);
	else if (*p == 'c')
		st.char_counter = dispatch_table[1](st, p, ap);
	else if (*p == 's')
		st.char_counter = dispatch_table[2](st, p, ap);
	if (*p == '\n' && ++st.char_counter)
		ft_putchar('\n');
	if (*p == '%' && ++st.char_counter)
		ft_putchar('%');
	//st.char_counter = CHECK(st, *p, ap);
	return (st.char_counter);
}

int	ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	const char	*p;
	t_var		st;

	va_start(ap, fmt);
	p = fmt;
	st.count = 0;
	st.char_counter = 0;
	while (*p)
	{
		if (*p != '%' && ++st.char_counter)
		{
			ft_putchar(*p++);
			continue ;
		}
		p++;
		while (*p == ' ' && ++st.count && ++st.char_counter)
			p++;
		if (st.count > 1)
			st.char_counter -= st.count;
		st.char_counter = check_ptr(st, p, ap);
		//st.char_counter = CHECK(st, *p, ap);
		p++;
		//st.char_counter++;
		st.count = 0;
	}
	va_end(ap);
	return (st.char_counter);
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