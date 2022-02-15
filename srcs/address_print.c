/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:31:57 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 17:39:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	address_print(t_var *st)				//only minus and width flags for pointers
{
	int		i;
	char	*str;
	
	i = 0;
	str = pf_itoa_base(va_arg(st->ap, long), 16, st->ptr);
	if (!str)
		exit (1);
	write(1, "0x", 2);
	st->char_count += 2;
	while (str[i] && ++st->char_count)
		ft_putchar(str[i++]);
	ft_strdel(&str);
	return ;
}
