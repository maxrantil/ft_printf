/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draft_ft_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/06 15:29:31 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_int(const char *fmt, int i, va_list	ap, t_var	var)
{
	if (fmt[i] == '%' && fmt[i + 1] == 'd')
	{
		var.d = va_arg(ap, int);
		ft_putnbr(var.d);
		return (1);
	}
	return (0);
}

int	is_char(const char *fmt, int i, va_list	ap, t_var	var)
{
	if (fmt[i] == '%' && fmt[i + 1] == 'c')
	{
		var.c = va_arg(ap, int);
		ft_putchar(var.c);
		return (1);
	}
	return (0);
}

int	is_str(const char *fmt, int i, va_list	ap, t_var	var)
{
	if (fmt[i] == '%' && fmt[i + 1] == 's')
	{
		var.s = va_arg(ap, char *);
		while (*var.s)
			ft_putchar(*var.s++);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_var	var;
	int		num_ap;
	int		i;

	va_start(ap, fmt);
	num_ap = ft_strlen(fmt);
	i = -1;
	while (++i < num_ap)
	{
		if (is_int(fmt, i, ap, var))
			i++;
		else if (is_char(fmt, i, ap, var))
			i++;
		else if (is_str(fmt, i, ap, var))
			i++;
		else if (fmt[i] == '\n')
			ft_putchar('\n');
		else
			ft_putchar(fmt[i]);
	}
	va_end(ap);
	return (1);
}

int	main(void)
{
	ft_printf("test  %d this %d %c %c %s\n", 4, 1, 'h', 'r', "end string");
	printf("% % %s\n", "this is printf string");
	ft_printf("% % %s\n", "this is printf string");
	printf("% d %s\n", 1, "this is printf string");
	ft_printf("% % %s\n", "this is printf string");
	//system("leaks a.out");
	return (0);
}
