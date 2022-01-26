/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/26 20:59:43 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> //ToDo: remove later

int	is_int(const char *placeholders, int i, va_list	args, t_var	var)
{
	if (placeholders[i] == '%' && placeholders[i + 1] == 'd')
	{
		var.d = va_arg(args, int);
		ft_putnbr(var.d);
		return (1);
	}
	return (0);
}

int	is_char(const char *placeholders, int i, va_list	args, t_var	var)
{
	if (placeholders[i] == '%' && placeholders[i + 1] == 'c')
	{
		var.c = va_arg(args, int);
		ft_putchar(var.c);
		return (1);
	}
	return (0);
}

/*
**		ToDo: Fix this
*/

int	is_str(const char *placeholders, int i, va_list	args, t_var	var)
{
	int	index;

	index = 0;
	if (placeholders[i] == '%' && placeholders[i + 1] == 's')
	{
		var.s = (char *)ft_memalloc(5);
		var.s[index] = va_arg(args, int);
		ft_putchar(var.s[index]);
		return (1);
	}
	return (0);
}

void	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	t_var	var;
	int		num_args;
	int		i;

	va_start(args, placeholders);
	num_args = ft_strlen(placeholders);
	i = -1;
	while (++i < num_args)
	{
		if (is_int(placeholders, i, args, var))
			i++;
		else if (is_char(placeholders, i, args, var))
			i++;
		else if (is_str(placeholders, i, args, var))
			i++;
		else if (placeholders[i] == '\n')
			ft_putchar('\n');
		else
			ft_putchar(placeholders[i]);

	}
	va_end(args);
}

int	main(void)
{
	ft_printf("test  %d this %d %c %c %s", 4, 1, 'h', 'r', "end string");
	//system("leaks a.out");

	//printf("\n%s\n", "this is printf string");
	return (0);
}
