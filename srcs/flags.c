/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/11 15:04:58 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
}

void	exec_flag_zero(t_var *st)
{
	long sub;

	sub = st->zero;
	sub -= (st->va_ret < 0);
	if (st->precision && st->zero_flag == ON)
		sub = st->precision - st->len_va_arg + st->len_va_arg;
	sub *= (sub > 0);
	while ((size_t)sub-- > st->len_va_arg)
		st->char_count += write(1, "0", 1);
	st->zero_flag = OFF;
}

void	get_flag_zero(t_var *st)
{
	if (*st->fmt == '0')
	{
		st->zero_flag = ON;
		while (*st->fmt == '0')
			st->fmt++;
		/* if (st->va_ret < 0)         			//why is this here? i dont need it, but will it make it faster?
			return ; */
		st->zero = get_it(st);
	}
}

void	hash_flag(t_var *st)
{
	if (*st->fmt == '#')
	{
		st->hash_flag = ON;
		st->fmt++;
	}
}

 void	exec_flag_proc(t_var *st)
 {
	size_t i;

	i = 0;
	if (*st->fmt == '%' && st->minus_flag == OFF)
	{
		while (++i < st->width)
			st->char_count += write(1, " ", 1);
		st->char_count += write(1, st->fmt, 1);
	}
	else if (*st->fmt == '%' && st->minus_flag == ON)
	{
		st->char_count += write(1, st->fmt, 1);
		while (++i < st->width)
			st->char_count += write(1, " ", 1);
	}
	st->fmt++;
 }
		

 void	get_flag_space(t_var *st)
{
		while (*st->fmt == ' ' && ++st->space_count)
			st->fmt++;
}

 void	exec_flag_space(t_var *st)
{
		if (ft_isalpha(*st->fmt) && st->space_count)
		{
			st->char_count += write(1, " ", 1);
			st->space_count = 0;
		}
	}

	/* while (*st->fmt == ' ' && ++st->space_count)
	{
		st->fmt++;
		continue ;
		if (*st->fmt != '%')
		{
			if (st->space_count > 1)
				st->char_count += write(1, " ", 1);
		}
		if (*st->fmt == 'd' && st->space_count > 1)
		{
			st->char_count += write(1, " ", 1);
			st->space_count = 0;
		} */
		/* else if (st->space_count > 1 && !st->plus_flag)
		{
			st->fmt++;
			++st->space_count;
		} */

/* if (*++st->fmt == '%' || *st->fmt == ' ')
		{
			st->space_count = 0;
			while (*st->fmt == ' ' && ++st->space_count)
				st->fmt++;
			if (*st->fmt == '%')
				st->char_count += write(1, st->fmt++, 1);
			if (!ft_isalpha(*st->fmt))
				continue ;
		} */

void	flag_plus(t_var *st)
{
	if (*st->fmt == '+')
	{
		st->plus_flag = ON;
		st->fmt++;
		st->char_count++;
	}
}

void	flag_minus(t_var *st)
{
	if (*st->fmt == '-')
	{
		st->minus_flag = ON;
		st->fmt++;
	}
}
