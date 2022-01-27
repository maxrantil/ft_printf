/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/27 19:33:06 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	int_innit(size_t c, const char *p, va_list	ap)
{
	if (*p == 'd')
	{
		if (c--)
			ft_putchar(' ');
		ft_putnbr(va_arg(ap, int));
	}
}

void	char_innit(const char *p, va_list	ap)
{
	if (*p == 'c')
		ft_putchar(va_arg(ap, int));
}

void	str_innit(const char *p, va_list	ap)
{
	char	*str;

	if (*p == 's')
	{
		str = va_arg(ap, char *);
		while (*str)
			ft_putchar(*str++);
	}
}

void	check_ptr(size_t	c, const char	*p, va_list	ap)
{
	int_innit(c, p, ap);
	char_innit(p, ap);
	str_innit(p, ap);
	if (*p == '\n')
		ft_putchar('\n');
}

int	ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	const char	*p;
	size_t		c;

	va_start(ap, fmt);
	p = fmt;
	c = 0;
	while (*p)
	{
		if (*p != '%')
		{
			ft_putchar(*p++);
			continue ;
		}
		p++;
		while (*p == ' ' && ++c)
			p++;
		check_ptr(c, p, ap);
		p++;
		c = 0;
	}
	va_end(ap);
	return (1);
}
