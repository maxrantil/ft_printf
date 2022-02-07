/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:28:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:43:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
** //more cases comming
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
