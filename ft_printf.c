/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:04:17 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putnbr(int n, t_var *st)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		pf_putnbr(nbr / 10, st);
		pf_putnbr(nbr % 10, st);
	}
	else
	{
		ft_putchar(nbr + 48);
		st->char_count++;
	}
	return (st->char_count);
}

int	int_print(t_var *st, const char *p, va_list ap)
{
	int		ret;

	ret = va_arg(ap, int);
	if (*p == 'd' || *p == 'i')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		if (ret)
			st->char_count = pf_putnbr(ret, st);
		return (st->char_count);
	}
	return (st->char_count);
}

int	char_print(t_var *st, const char *p, va_list ap)
{
	if (*p == 'c' && ++st->char_count)
	{
		ft_putchar(va_arg(ap, int));
		return (st->char_count);
	}
	return (st->char_count);
}

int	str_print(t_var *st, const char *p, va_list ap)
{
	char	*str;

	if (*p == 's')
	{
		str = va_arg(ap, char *);
		while (*str && ++st->char_count)
			ft_putchar(*str++);
		return (st->char_count);
	}
	return (st->char_count);
}

int	uint_print(t_var *st, const char *p, va_list ap)
{
	if (*p == 'u')
	{
		if (st->space_count-- && st->char_count++)
			ft_putchar(' ');
		ft_putnbr(va_arg(ap, int));
		return (++st->char_count);
	}
	return (st->char_count);
}

/*
** //more cases comming with %% and more
*/

int	check_ptr(t_var *st, const char	*p, va_list	ap)
{	
	int		i;

	i = 0;
	while (TABLE_POS[i] && TABLE_POS[i] != *p)
		i++;
	if (*p == '\n' && ++st->char_count)
		ft_putchar('\n');
	else if (*p == '%' && ++st->char_count)
		ft_putchar('%');
	else if (TABLE_POS[i] == '\0')
		return (0);
	else 
		st->char_count = dispatch_table[i](st, p, ap);
	return (st->char_count);
}

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