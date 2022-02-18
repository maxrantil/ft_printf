/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/18 17:06:04 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
	return ;
}

void	exec_flag_zero(t_var *st)
{
	if (st->int_ret < 0)
		--st->zero;
	while (st->zero-- > st->len_va_arg && ++st->char_count)
		ft_putchar('0');
	st->zero_flag = OFF;
}

void	get_flag_zero(t_var *st)
{
	int c_single;
	
	c_single = 0;
	st->zero_flag = ON;
	while (*st->ptr == '0')
		st->ptr++;
	/* if (st->int_ret < 0)
		return ; */
	if (ft_isdigit(*st->ptr))			//take aaway?
	{	
		while (ft_isdigit(*st->ptr) && ++c_single)
		{
			if (c_single == 1 && ++c_single)
				st->zero = *st->ptr - 48;
			else	
				st->zero = st->zero * 10 + (*st->ptr - 48);
			st->ptr++;
		}
	}
}

void	hash_flag(t_var *st)
{
	st->hash_flag = ON;
	st->ptr++;
}

void	get_flag_space(t_var *st)
{
	while (*st->ptr == ' ' && ++st->space_count && ++st->char_count)
			st->ptr++;
	if (st->space_count > 1)					//is this nessesary?
		st->char_count -= st->space_count;
}

void	exec_flag_space(t_var *st)
{
	if (st->int_ret < 0)
		return ;
	if (st->space_count-- && ++st->char_count)
		ft_putchar(' ');
}

void	flag_plus(t_var *st)
{
	if (*st->ptr == '+')
	{
		st->plus_flag = ON;
		//st->enum_flags[0] ^= 1 << 0; 
		//st->enum_flags[0] = 1 << 0; 		//hardcoded 0 			// 0000 0000 0000 0001 to 0000 0000 0000 0001
		//st->enum_flags[0] = 2 << 1; 		//hardcoded 0 			// 0000 0000 0000 0010 to 0000 0000 0000 0100
		// enum_flags[0] == 1 // 0000 0000 0000 0001
		// if flags0 == PLUS; // om flag0 (1) == MINUS (2) // FALSE
		// if flag0 & MINUS != 0 // om flag0 (0000 0000 0000 0001) och MINUS (0000 0000 0000 0010) = 0000 0000 0000 0001
		// minus + space = 2 + 4 == 6; //  0000 0000 0000 0110
		// if flag0 & minus + space != 0 // om flag0 (0000 0000 0000 0001) och minus + space (0000 0000 0000 0110) 
		//= 0000 0000 0000 0000
		
		st->ptr++;
		st->char_count++;
	}
}

void	flag_minus(t_var *st)
{
	if (*st->ptr == '-')
	{
		st->minus_flag = ON;  //here i can inplement the bitwise number
		//st->enum_flags[1] ^= 1 << 1;
		st->ptr++;
	}
	return ;
}

void	procentage_print(t_var *st)
{
	ft_putchar(*st->ptr);
	++st->char_count;
	return ;
}
