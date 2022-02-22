/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/22 16:19:19 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_put_uint(t_var *st)
{
	if (st->plus_flag == ON)
	{
		st->plus_flag = OFF;
		ft_putchar('+');
		exec_precision(st);
	}
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
}

int	uint_nbrlen(unsigned long long nbr) //write this cleaner, you can
{
	int	c;

	c = 0;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		c++;
	}
	return (++c);
}

char	*conv_uint_to_str(unsigned long long nbr, t_var *st)
{
	char	*str; //can you use pointer instead of index? shall you send in st to take the return directly in here insted of sending it out?
	int		l;

	st->va_ret = nbr;
	l = uint_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1); //need to be freed
	if (!str)
		exit(1);
	str[l] = '\0';
	while (l--)
	{
		str[l] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}

void	uint_print(t_var *st)
{
	if (st->le_unsigned_short == ON) //make this into a function in itself
		st->hold_str = conv_uint_to_str((unsigned short)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_char == ON)
		st->hold_str = conv_uint_to_str((unsigned char)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_long == ON)
		st->hold_str = conv_uint_to_str((unsigned long)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_long_long == ON)
		st->hold_str = conv_uint_to_str((unsigned long long)va_arg(st->ap, unsigned long long), st);
	else
		st->hold_str = conv_uint_to_str((unsigned int)va_arg(st->ap, unsigned long long), st);

	st->len_va_arg = ft_strlen(st->hold_str); // can all this be one function??

	asterix_print(st);
	if (st->minus_flag == OFF && st->width)
	{
		exec_width(st);
	}
	exec_flag_space(st);
	exec_precision(st);
	exec_flag_zero(st);

	pf_put_uint(st);  //this is all the same as int, make one function?
	//need to free after there somewhere
}
