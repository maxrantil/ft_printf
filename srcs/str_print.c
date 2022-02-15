/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 17:27:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	str_print(t_var *st)
{
	char	*str;

	str = va_arg(st->ap, char *);
	st->len_va_arg = ft_strlen(str);
	asterix_print(st);
	while (*str && ++st->char_count)
		ft_putchar(*str++);
	return ;
}
