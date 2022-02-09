/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 17:02:03 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	const char	*ptr;
	t_var		st;

	va_start(ap, fmt);
	ptr = fmt;
	st.space_count = 0;
	st.char_count = 0;
	while (*ptr)
	{
		if (*ptr != '%' && ++st.char_count)
		{
			ft_putchar(*ptr++);
			continue ;
		}
		ptr++;
		while (*ptr == ' ' && ++st.space_count && ++st.char_count)
			ptr++;
		if (st.space_count > 1)
			st.char_count -= st.space_count;
		st.char_count = check_ptr(&st, ptr, ap);
		if (!st.char_count)
			return (-1);
		ptr++;
		st.space_count = 0;
	}
	va_end(ap);
	//system("leaks a.out");
	return (st.char_count);
}
