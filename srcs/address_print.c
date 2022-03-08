/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:31:57 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 19:31:25 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	address_print(t_var *st)				//only minus and width flags for pointers
{
	char	*str;
	
	pf_itoa_base(va_arg(st->ap, long), 16, st);
	write(1, "0x", 2);
	st->char_count += 2;
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	ft_strdel(&str);
	return ;
}
