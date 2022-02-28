/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/28 20:13:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <assert.h>

static unsigned int tests;
static unsigned int done;

void mix_ezz(void)
{
	int	a;
	int	b;
	b = printf("%u\n", 4);
	a = ft_printf("%u\n", 4);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ezz failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez1(void)
{
	int	a;
	int	b;
	b = printf("printf: test %u this %i\n", 0, 4);
	a = ft_printf("ft_pri: test %u this %i\n", 0, 4);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez1 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez2(void)
{
	int	a;
	int	b;
	b = printf("printf: this %i\n", 1);
	a = ft_printf("ft_pri: this %i\n", 1);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez2 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez3(void)
{
	int	a;
	int	b;
	b = printf("printf: test %d %% this %i\n", 0, 4);
	a = ft_printf("ft_pri: test %d %% this %i\n", 0, 4);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez3 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez4(void)
{
	int	a;
	int	b;
	b = printf("printf: test %u %d this %i %s %c\n", 0, 4, 1, "hej", 'b');
	a = ft_printf("ft_pri: test %u %d this %i %s %c\n", 0, 4, 1, "hej", 'b');
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez4 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_oct_zero(void)
{
	int	a;
	int	b;
	b = printf("printf: oct: %o\n", 0);
	a = ft_printf("ft_pri: oct: %o\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_oct_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_oct(void)
{
	int	a;
	int	b;
	b = printf("printf: oct: %o\n", 123432);
	a = ft_printf("ft_pri: oct: %o\n", 123432);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_oct failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex(void)
{
	int	a;
	int	b;
	b = printf("printf: hex: %X \n", 1234554321);
	a = ft_printf("ft_pri: hex: %X \n", 1234554321);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex_zero(void)
{
	int	a;
	int	b;
	b = printf("printf: hex: %X \n", 0);
	a = ft_printf("ft_pri: hex: %X \n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_dec(void)
{
	int	a;
	int	b;

	b = printf("printf: decimal  %d\n", 32456);
	a = ft_printf("ft_pri: decimal  %d\n", 32456);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n _______test_dec failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int(void)
{
	int	a;
	int	b;

	b = printf("printf: decimal  %i\n", 32456);
	a = ft_printf("ft_pri: decimal  %i\n", 32456);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n _______test_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex_random(void)
{
	int	a;
	int	b;
	b = printf("printf: hex: %X \n", 17);
	a = ft_printf("ft_pri: hex: %X \n", 17);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex_random failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_zero(void)
{
	int	a;
	int	b;
	b = printf("printf: dec: %d \n", 0);
	a = ft_printf("ft_pri: dec: %d \n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_minus(void)
{
	int	a;
	int	b;
	b = printf("printf dec: %d \n", -22);
	a = ft_printf("ft_pri dec: %d \n", -22);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_minus failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_plus_flag(void)
{
	int	a;
	int	b;
	b = printf("printf dec: %+d more\n", 234);
	a = ft_printf("ft_pri dec: %+d more\n", 234);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_plus_flag failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_plus_flag2(void)
{
	int	a;
	int	b;
	b = printf("%+dtext", 21);
	a = ft_printf("%+dtext", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_plus_flag2 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_minusminus_flag(void)
{
	int	a;
	int	b;
	b = printf("printf dec: %+d more\n", -2);
	a = ft_printf("ft_pri dec: %+d more\n", -2);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_minusminus_flag failed_______\x1b[0m\n\n"));
	++done;
}

void	test_procentage(void)
{
	int	a;
	int	b;
	b = printf("printf dec: %%\n");
	a = ft_printf("ft_pri dec: %%\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_procentage failed_______\x1b[0m\n\n"));
	++done;
}

void	test_address(void)
{
	int	a;
	int	b;
	b = printf("printf address: %p\n", &a);
	a = ft_printf("ft_pri address: %p\n", &a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_address failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_int(void)
{
	int	a;
	int	b;
	b = printf("printf: %*d\n", 20, 21);
	a = ft_printf("ft_pri: %*d\n", 20, 21);
	printf("ret: %d \n", b);
	printf("\nret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_str(void)
{
	int	a;
	int	b;
	b = printf("printf: %*s\n", 76, "this is a string");
	a = ft_printf("ft_pri: %*s\n", 76, "this is a string");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_str failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_int_plus(void)
{
	int	a;
	int	b;
	b = printf("printf: %+*d\n", 20, 21);
	a = ft_printf("ft_pri: %+*d\n", 20, 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_single(void)
{
	int	a;
	int	b;
	b = printf("pri: %4d\n", 21);
	a = ft_printf("ft_: %4d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_single failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_multi(void)
{
	int	a;
	int	b;
	b = printf("pri: %14d\n", 21);
	a = ft_printf("ft_: %14d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_multi failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_multi2(void)
{
	int	a;
	int	b;
	b = printf("pri: %114d\n", 21);
	a = ft_printf("ft_: %114d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_multi2 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_precision(void)
{
	int	a;
	int	b;
	b = printf("pri: %.4d\n", 21);
	a = ft_printf("ft_: %.4d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_precision failed_______\x1b[0m\n\n"));
	++done;
}

void	test_precision_1(void)
{
	int	a;
	int	b;
	b = printf("%.8d\n", 21);
	a = ft_printf("%.8d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_precision_1 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck(void)
{
	int	a;
	int	b;
	b = printf("pri: %8.3dLol\n", 42);
	a = ft_printf("ft_: %8.3dLol\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minus(void)
{
	int	a;
	int	b;
	b = printf("pri: %-10.5dLol\n", 42);
	a = ft_printf("ft_: %-10.5dLol\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminus(void)
{
	int	a;
	int	b;
	b = printf("pri: %-10.7dLol\n", -42);
	a = ft_printf("ft_: %-10.7dLol\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_simpleminus(void)
{
	int	a;
	int	b;
	b = printf("pri: %10.5dLol\n", -42);
	a = ft_printf("ft_: %10.5dLol\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_simpleminus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminint(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %-30.25dLol\n", b);
	a = ft_printf("ft_: %-30.25dLol\n",a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminint failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminint2(void)
{
	long	a = -2147483648;
	long	b = -2147483648;
	b = printf("pri: %13.13dLol\n", (int)b);
	a = ft_printf("ft_: %13.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminint2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz(void)
{
	long	a = -214;
	long	b = -214;
	b = printf("pri: %+13.13dLol\n", (int)b);
	a = ft_printf("ft_: %+13.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz2(void)
{
	long	a = 2147483647;
	long	b = 2147483647;
	b = printf("pri: %+13.13dLol\n", (int)b);
	a = ft_printf("ft_: %+13.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz3(void)
{
	long	a = -214;
	long	b = -214;
	b = printf("pri: %+113.13dLol\n", (int)b);
	a = ft_printf("ft_: %+113.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz3 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz4(void)
{
	long	a = 2147483647;
	long	b = 2147483647;
	b = printf("pri: %+13.83dLol\n", (int)b);
	a = ft_printf("ft_: %+13.83dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz4 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_space_minus(void)
{
	int	a;
	int	b;
	b = printf("pri: %     dLol\n", -2147483647);
	a = ft_printf("ft_: %     dLol\n", -2147483647);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_space_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_space(void)
{
	int	a;
	int	b;
	b = printf("pri: %  dLol\n", 7483647);
	a = ft_printf("ft_: %  dLol\n", 7483647);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_space failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h(void)
{
	int	a = -32769;
	int	b = -32769;
/* 	int b;
	int a; */
	b = printf("pri: %hd\n", (short)b);
	a = ft_printf("ft_: %hd\n", (short)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h2(void)
{
	int	a = -327;
	int	b = -327;
/* 	int b;
	int a; */
	b = printf("%hd\n", (short)b);
	a = ft_printf("%hd\n", (short)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_42hex(void)
{
	int	a;
	int	b;
	b = printf("pri: %x\n", 42);
	a = ft_printf("ft_: %x\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_42hex failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh(void)
{
	int	a;
	int	b;
	b = printf("%hhd\n", (signed char)287);
	a = ft_printf("%hhd\n", (signed char)287);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh2(void)
{
	signed char	a = 40;
	signed char	b = 40;
	b = printf("%hhd\n", b);
	a = ft_printf("%hhd\n", a);
	printf("\nret: %hhd \n", b);
	printf("ret: %hhd \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh_unsigned_int(void)
{
	int	a = 4000000;
	int	b = 4000000;
	b = printf("%hhu\n", (unsigned char)b);
	a = ft_printf("%hhu\n", (unsigned char)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh_unsigned_int2(void)
{
	int	a = -400;
	int	b = -400;
	b = printf("pri: %hhu\n", (unsigned char)b);
	a = ft_printf("ft_: %hhu\n", (unsigned char)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh_unsigned_int2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h_unsigned_int(void)
{
	int	a = 4000000;
	int	b = 4000000;
	b = printf("%hu\n", (unsigned short)b);
	a = ft_printf("%hu\n", (unsigned short)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h_unsigned_int2(void)
{
	int	a = -400;
	int	b = -400;
	b = printf("pri: %hu\n", (unsigned short)b);
	a = ft_printf("ft_: %hu\n", (unsigned short)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h_unsigned_int2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_intmin(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %d\n", b);
	a = ft_printf("ft_: %d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_test_intmin failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashoct(void)
{
	int	a = 648;
	int	b = 648;
	b = printf("pri: %#o\n", b);
	a = ft_printf("ft_: %#o\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashoct failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashoct_intmin(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %#o\n", b);
	a = ft_printf("ft_: %#o\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashoct_intmin failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashhex_intmax(void)
{
	int	a = 2147483647;
	int	b = 2147483647;
	b = printf("pri: %#x\n", b);
	a = ft_printf("ft_: %#x\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashhex_intmax failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashhex_intmin(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %#X\n", b);
	a = ft_printf("ft_: %#X\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashhex_intmin failed_______\x1b[0m\n\n"));
	++done;
}

void	test_binary(void)
{
	ft_printf("\n(ft_printf binary: %b)\n\n\n", 128);
	++tests;
	++done;
}

void test_flag_zero(void)
{
	int	a = 483648;
	int	b = 483648;
	b = printf("pri: %012d\n", b);
	a = ft_printf("ft_: %012d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero1(void)
{
	int	a = -2147;
	int	b = -2147;
	b = printf("pri: %0000012d\n", b);
	a = ft_printf("ft_: %0000012d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero1 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero2(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %014d\n", b);
	a = ft_printf("ft_: %014d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %014.16d\n", b);
	a = ft_printf("ft_: %014.16d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre2(void)
{
	int	a = 3648;
	int	b = 3648;
	b = printf("pri: %019.12d\n", b);
	a = ft_printf("ft_: %019.12d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre3(void)
{
	int	a = 3648;
	int	b = 3648;
	b = printf("pri: %085.12d\n", b);
	a = ft_printf("ft_: %085.12d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre3 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre4(void)
{
	int	a = 3648;
	int	b = 3648;
	b = printf("pri: %0850.12d\n", b);
	a = ft_printf("ft_: %0850.12d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre4 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre5(void)
{
	int	a = 3648;
	int	b = 3648;
	b = printf("pri: %085.120d\n", b);
	a = ft_printf("ft_: %085.120d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre5 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_zero_with_pre6(void)
{
	int	a = -3648;
	int	b = -3648;
	b = printf("pri: %085.120d\n", b);
	a = ft_printf("ft_: %085.120d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_zero_with_pre6 failed_______\x1b[0m\n\n"));
	++done;
}

void test_dubbleint(void)
{
	int	a;
	int	b;
	b = printf("pri: %d%d%i%i\n", 1, 1, 2, 2);
	a = ft_printf("ft_: %d%d%i%i\n", 1, 1, 2, 2);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_dubbleint failed_______\x1b[0m\n\n"));
	++done;
}

void test_simple_string(void)
{
	int	a;
	int	b;
	b = printf("pri: %s\n", "this is a simple string");
	a = ft_printf("ft_: %s\n", "this is a simple string");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_simple_string failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_l(void)
{
	int	a = 4000000;
	int	b = 4000000;
	b = printf("%li\n", (long)b);
	a = ft_printf("%li\n", (long)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_l failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_l_minus(void)
{
	unsigned long	a = -400;
	unsigned long	b = -400;
	b = printf("pri: %lu\n", b);
	a = ft_printf("ft_: %lu\n", a);
	printf("\nret: %lu \n", b);
	printf("ret: %lu \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_l_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_ll(void)
{
	int	a = 4000000;
	int	b = 4000000;
	b = printf("%llu\n", (unsigned long long)b);
	a = ft_printf("%llu\n", (unsigned long long)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_ll failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_ll_minus(void)
{
	int	a = -400;
	int	b = -400;
	b = printf("pri: %lld\n", (long long)b);
	a = ft_printf("ft_: %lld\n", (long long)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_ll_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_ll_test(void)
{
	int	a = -400;
	int	b = -400;
	b = printf("pri: %d\n", b);
	a = ft_printf("ft_: %d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_ll_test failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_ll_str(void)
{
	int	a;
	int	b;
	b = printf("pri: %s\n", "we try this");
	a = ft_printf("ft_: %s\n", "we try this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_ll_str failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_ll_test_uint(void)
{
	unsigned int	a = 400;
	unsigned int	b = 400;
	b = printf("pri: %d\n", b);
	a = ft_printf("ft_: %d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_ll_test_uint failed_______\x1b[0m\n\n"));
	++done;
}

void test_multi_flags0(void)			//this need debugging
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %+016d\n", b);
	a = ft_printf("ft_: %+016d\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_multi_flags0 failed_______\x1b[0m\n\n"));
	++done;
}

void test_multi_flags1(void)
{
	int	a = -2147483648;
	int	b = -2147483648;
	b = printf("pri: %u\n", (unsigned int)b);
	a = ft_printf("ft_: %u\n", (unsigned int)a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_multi_flags1 failed_______\x1b[0m\n\n"));
	++done;
}

void test_multi_flags2(void)
{
	long long unsigned a = 1844674407370951615;
	long long unsigned b = 1844674407370951615;
	b = printf("pri: %030llu\n", b);
	a = ft_printf("ft_: %030llu\n", a);
	printf("\nret: %llu \n", b);
	printf("ret: %llu \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_multi_flags2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_multi_flags3(void)
{
	long long	a = -9223372036854775807;
	long long	b = -9223372036854775807;
	b = printf("pri: %045lld\n", b);
	a = ft_printf("ft_: %045lld\n", a);
	printf("\nret: %lld \n", b);
	printf("ret: %lld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_multi_flags3 failed_______\x1b[0m\n\n"));
	++done;
}

void test_multi_flags4(void)
{
	unsigned long	a = 4294967295;
	unsigned long	b = 4294967295;
	b = printf("pri: %-lu\n", b);
	a = ft_printf("ft_: %-lu\n", a);
	printf("\nret: %lu \n", b);
	printf("ret: %lu \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_multi_flags4 failed_______\x1b[0m\n\n"));
	++done;
}

void	leo_test(void)
{
	int	a = 429;
	int	b = 429;										//debugg this
	b = printf("pri: %+10.5dLol\n", b);
	a = ft_printf("ft_: %+10.5dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______leo_test failed_______\x1b[0m\n\n"));
	++done;
}

void	pro_test(void)
{
	int	a = 429;
	int	b = 429;										//debugg this
	b = printf("pri: %%%%%%+10.5dLol\n", b);
	a = ft_printf("ft_: %%%%%%+10.5dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______pro_test failed_______\x1b[0m\n\n"));
	++done;
}

void	pro_test1(void)
{
	int	a = 429;
	int	b = 429;										//debugg this
	b = printf("pri: %%%%%%%+10.5dLol\n", b);
	a = ft_printf("ft_: %%%%%%%+10.5dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______pro_test1 failed_______\x1b[0m\n\n"));
	++done;
}


int	main(void)
{
	mix_ezz();
	mix_ez1();
	mix_ez2();
	mix_ez3();
	mix_ez4();
	test_oct_zero();
	test_oct();
	test_int();
	test_hex();
	test_hex_zero();
	test_dec();
	test_hex_random();
	test_int_zero();
	test_int_minus();
	test_int_plus_flag();
	test_int_plus_flag2();
	test_int_minusminus_flag();
	test_procentage();
	test_address();
	test_asterix_with_int();
	test_asterix_with_str();
	test_width_single();
	test_width_multi();
	test_width_multi2();
 	test_precision();
 	test_precision_1();
	test_mindfuck();
	test_mindfuck_minus();
	test_mindfuck_minusminus();
	test_mindfuck_simpleminus();
 	test_mindfuck_minusminint();
	test_mindfuck_minusminint2();
	test_mindfuck_plus_craz();
	test_mindfuck_plus_craz2();
	test_mindfuck_plus_craz3();
	test_mindfuck_plus_craz4();
	test_flag_space_minus();
	test_flag_space();
	test_length_h();
	test_length_h2();
	test_length_hh();
	test_length_hh2();
	test_length_hh_unsigned_int();
	test_length_hh_unsigned_int2();
	test_length_h_unsigned_int();
	test_length_h_unsigned_int2();
	test_intmin();
	test_42hex();
	test_asterix_with_int_plus(); //need more tests shere with width, precision, and minus flag
	test_hashoct();
	test_hashoct_intmin();
	test_hashhex_intmin();
	test_hashhex_intmax();
	test_binary();
	test_flag_zero();
	test_flag_zero1();
	test_flag_zero2();
	test_flag_zero_with_pre();
	test_flag_zero_with_pre2();
	test_flag_zero_with_pre3();
	test_flag_zero_with_pre4();
	test_flag_zero_with_pre5();
	test_flag_zero_with_pre6(); //you rock Max! incredible determination and stamina
	test_dubbleint();
	test_simple_string();
	test_length_l();
	test_length_l_minus();
	test_length_ll();
	test_length_ll_minus();
	test_length_ll_test();
	test_length_ll_str();
	test_length_ll_test_uint();
	test_multi_flags0();
	test_multi_flags1();
	test_multi_flags2();
	test_multi_flags3();
	test_multi_flags4();
	leo_test();
	pro_test();
	pro_test1();					//need more 0 tests. BUT YOU ARE AMAZING DUDE! <3

	printf("\n%d/%d completed\n", tests, done);
	return (0);
}

	//- %[flags][width][.precision][length]specifier

	//print order:
    /*
        width (if flagcombo != dash)
        PLUS FLAG (plus/minus) / - om negativt
        HASHflag (0/0x/0X)
        0 / precision // 0 flag ignored when precision > 0.
        (precision == absolute number of 0 + digits - HASH_num.
        width (if flagcombo == dash)

    */