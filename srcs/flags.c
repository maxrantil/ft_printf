/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/17 16:37:19 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
	return ;
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
	if (st->space_count > 1)
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
		//check_parser(st);
	}
	return ;
}

void	flag_minus(t_var *st)
{
	if (*st->ptr == '-')
	{
		st->minus_flag = ON;  //here i can inplement the bitwise number
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
