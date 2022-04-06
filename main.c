/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/06 17:26:31 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <assert.h>
#include <limits.h>

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
		assert(printf("\033[1;31m _______test_ezz failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_ez1 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_ez2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_ez3 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_ez4 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_oct_zero failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_oct failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hex failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hex_zero failed_______\033[0m\n\n"));
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
		assert(printf("\n _______test_dec failed_______\033[0m\n\n"));
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
		assert(printf("\n _______test_int failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hex_random failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_int_zero failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_int_minus failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_int_plus_flag failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_int_plus_flag2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_int_minusminus_flag failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_address failed_______\033[0m\n\n"));
	++done;
}

void	test_asterix_with_str(void)
{
	int	a;
	int	b;
	b = printf("printf: [%+*d]\n", 16, 16465);
	a = ft_printf("ft_pri: [%+*d]\n", 16, 16465);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_asterix_with_str failed_______\033[0m\n\n"));
	++done;
}

void	test_asterix_with_int(void)
{
	int	a;
	int	b;
	b = printf("printf: [%+*d]\n", 7, -2142);
	a = ft_printf("ft_pri: [%+*d]\n", 7, -2142);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_asterix_with_int failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_width_single failed_______\033[0m\n\n"));
	++done;
}

void	test_width_multi(void)
{
	int	a;
	int	b;
	b = printf("pri: %-14d\n", 21);
	a = ft_printf("ft_: %-14d\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_width_multi failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_width_multi2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_precision failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_precision_1 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_minusminus failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_minusminint failed_______\033[0m\n\n"));
	++done;
}

void test_mindfuck_minusminint2(void)
{
	long	a = -2147483648;
	long	b = -2147483648;
	b = printf("pri: %33.13dLol\n", (int)b);
	a = ft_printf("ft_: %33.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_mindfuck_minusminint2 failed_______\033[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz(void)
{
	long	a = -214;
	long	b = -214;
	b = printf("pri: %+33.13dLol\n", (int)b);
	a = ft_printf("ft_: %+33.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_mindfuck_plus_craz failed_______\033[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz2(void)
{
	long	a = 2147483647;
	long	b = 2147483647;
	b = printf("pri: %+33.13dLol\n", (int)b);
	a = ft_printf("ft_: %+33.13dLol\n",(int)a);
	printf("\nret: %ld \n", b);
	printf("ret: %ld \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_mindfuck_plus_craz2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_plus_craz3 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_plus_craz4 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_h failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_h2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_42hex failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_hh failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_hh2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_hh_unsigned_int failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_hh_unsigned_int2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_h_unsigned_int failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_h_unsigned_int2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_test_intmin failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hashoct failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hashoct_intmin failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hashhex_intmax failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_hashhex_intmin failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero1 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre3 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre4 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre5 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_zero_with_pre6 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_dubbleint failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_simple_string failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_l failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_l_minus failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_ll failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_ll_minus failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_ll_test failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_ll_str failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_length_ll_test_uint failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_multi_flags0 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_multi_flags1 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_multi_flags2 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_multi_flags3 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_multi_flags4 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______leo_test failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_procentage failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_flag_space_minus failed_______\033[0m\n\n"));
	++done;
}

void test_flag_space(void)
{
	int	a;
	int	b;
	b = printf("pri: %  d Lol\n", 7483647);
	a = ft_printf("ft_: %  d Lol\n", 7483647);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_flag_space failed_______\033[0m\n\n"));
	++done;
}

void	test_float0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%25.9f] Lol\n", 5.43211234567890);
	a = ft_printf("ft_: [%25.9f] Lol\n", 5.43211234567890);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float0 failed_______\033[0m\n\n"));
	++done;
}

void	test_float1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%25.9f] Lol\n", -5.43211234567890);
	a = ft_printf("ft_: [%25.9f] Lol\n", -5.43211234567890);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float1 failed_______\033[0m\n\n"));
	++done;
}

void	test_float2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%4.33f] Lol\n", 5.43211234567890);
	a = ft_printf("ft_: [%4.33f] Lol\n", 5.43211234567890);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float2 failed_______\033[0m\n\n"));
	++done;
}

void	test_float3(void)
{
	int	a;
	int	b;
	b = printf("pri: [%23.15f] Lol\n", 666.66666666666);
	a = ft_printf("ft_: [%23.15f] Lol\n", 666.66666666666);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float3 failed_______\033[0m\n\n"));
	++done;
}

void	test_float4(void)
{
	int	a;
	int	b;
	b = printf("pri: [%15.23f] Lol\n", 5555.5555555555555);
	a = ft_printf("ft_: [%15.23f] Lol\n", 5555.5555555555555);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float4 failed_______\033[0m\n\n"));
	++done;
}

void	test_float5(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#23.17f] Lol\n", 5.432112345678911111);
	a = ft_printf("ft_: [%#23.17f] Lol\n", 5.432112345678911111);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float5 failed_______\033[0m\n\n"));
	++done;
}

void	test_float6(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#17.23Lf] Lol\n", 5.43211234567890123456789098765L);
	a = ft_printf("ft_: [%#17.23Lf] Lol\n", 5.43211234567890123456789098765L);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float6 failed_______\033[0m\n\n"));
	++done;
}

void	test_float7(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#19.f]\n", 999999999.9999996);
	a = ft_printf("ft_: [%#19.f]\n", 999999999.9999996);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float7 failed_______\033[0m\n\n"));
	++done;
}

void	test_float8(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#Lf]\n", -0.0L);
	a = ft_printf("ft_: [%#Lf]\n", -0.0L);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float8 failed_______\033[0m\n\n"));
	++done;
}

void	test_float9(void)
{
	int	a;
	int	b;
	b = printf("pri: [%12.3f]\n", -0.0);
	a = ft_printf("ft_: [%12.3f]\n", -0.0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float9 failed_______\033[0m\n\n"));
	++done;
}

void	test_float10(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-10.0f]\n", 0.5);
	a = ft_printf("ft_: [%-10.0f]\n", 0.5);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float10 failed_______\033[0m\n\n"));
	++done;
}

void	test_float11(void)
{
	int	a;
	int	b;
	b = printf("pri: [%+.0f]\n", 1.5);
	a = ft_printf("ft_: [%+.0f]\n", 1.5);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float11 failed_______\033[0m\n\n"));
	++done;
}

void	test_float12(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-.3f]\n", -1.899999);
	a = ft_printf("ft_: [%-.3f]\n", -1.899999);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_float12 failed_______\033[0m\n\n"));
	++done;
}

void	test_basic2(void)
{
	int	a;
	int	b;
	b = printf("pri: %10x\n", 42);
	a = ft_printf("ft_: %10x\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic2 failed_______\033[0m\n\n"));
	++done;
}

void	test_basic3(void)
{
	int	a;
	int	b;
	b = printf("pri: %-10x\n", 42);
	a = ft_printf("ft_: %-10x\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic3 failed_______\033[0m\n\n"));
	++done;
}

void	test_basic4(void)
{
	int	a;
	int	b;
	b = printf("pri: %lx\n", 4294967296);
	a = ft_printf("ft_: %lx\n", 4294967296);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic4 failed_______\033[0m\n\n"));
	++done;
}

void	pro_test(void)
{
	int	a;
	int	b;
	b = printf("pri: %%%%%%%10.5d     Lol\n", 429);
	a = ft_printf("ft_: %%%%%%%10.5d     Lol\n", 429);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test failed_______\033[0m\n\n"));
	++done;
}

void	pro_test1(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %%%%%%%-10.5dLol\n", b);
	a = ft_printf("ft_: %%%%%%%-10.5dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test1 failed_______\033[0m\n\n"));
	++done;
}

void	pro_test2(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %%  %%    %%      %+10.5dLol\n", b);
	a = ft_printf("ft_: %%  %%    %%      %+10.5dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test2 failed_______\033[0m\n\n"));
	++done;
}

void	pro_test33(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %   %%%%%%- 5.10dLol\n", b);
	a = ft_printf("ft_: %   %%%%%%- 5.10dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test3 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_minus failed_______\033[0m\n\n"));
	++done;
}

void	test_basic5(void)
{
	int	a;
	int	b;
	b = printf("pri: %5.2d\n", 5427);
	a = ft_printf("ft_: %5.2d\n", 5427);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic5 failed_______\033[0m\n\n"));
	++done;
}

void	pro_test3(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %   %%%%%%- 5.15dLol\n", b);
	a = ft_printf("ft_: %   %%%%%%- 5.15dLol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test3 failed_______\033[0m\n\n"));
	++done;
}

void	basic_simple_proc(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: % d\n",9999);
	a = ft_printf("ft_: % d\n",9999);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_simple_proc failed_______\033[0m\n\n"));
	++done;
}

void	basic_plus_uint(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %.29lu\n", 4294967295);
	a = ft_printf("ft_: %.29lu\n", 4294967295);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_plus_uint failed_______\033[0m\n\n"));
	++done;
}

void	basic_valt(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %.10% %%\n");
	a = ft_printf("ft_: %.10% %%\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_valtfailed_______\033[0m\n\n"));
	++done;
}



void	pro_test4(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %%%   %  %+10.5d	Lol\n", b);
	a = ft_printf("ft_: %%%   %  %+10.5d	Lol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test4 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hash(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %#8x Lol\n", b);
	a = ft_printf("ft_: %#8x Lol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash failed_______\033[0m\n\n"));
	++done;
}

void	basic_hash1(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %#08x Lol\n", b);
	a = ft_printf("ft_: %#08x Lol\n", a);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash1 failed_______\033[0m\n\n"));
	++done;
}

void	test_basic6(void)
{
	int	a;
	int	b;
	b = printf("pri: %#x\n", 0);
	a = ft_printf("ft_: %#x\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic6 failed_______\033[0m\n\n"));
	++done;
}

 void	basic_hash2(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: %#08x Lol\n", 21);
	a = ft_printf("ft_: %#08x Lol\n", 21);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash2 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hash3(void)
{
	int	a;
	int	b;
	b = printf("pri: %#.x %#.0x-\n", 0, 0);
	a = ft_printf("ft_: %#.x %#.0x-\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash3 failed_______\033[0m\n\n"));
	++done;
}

void	basic_char1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%5c]\n", 42);
	a = ft_printf("ft_: [%5c]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_char1 failed_______\033[0m\n\n"));
	++done;
}

void	basic_char2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-5c]\n", 42);
	a = ft_printf("ft_: [%-5c]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_char2 failed_______\033[0m\n\n"));
	++done;
}

void	basic_char3(void)
{
	int	a;
	int	b;
	b = printf("pri: [%2c]\n", 0);
	a = ft_printf("ft_: [%2c]\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_char3 failed_______\033[0m\n\n"));
	++done;
}

void	basic_o_spec(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#6o]\n", 2500);
	a = ft_printf("ft_: [%#6o]\n", 2500);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_o_spec failed_______\033[0m\n\n"));
	++done;
}

void	basic_o_spec1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-#9o]\n", 2500);
	a = ft_printf("ft_: [%-#9o]\n", 2500);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_o_spec1 failed_______\033[0m\n\n"));
	++done;
}

void	basic_o_spec2(void)
{
	int	a;
	int	b;
	b = printf("pri: @moulitest2: [%.o %.0o]\n", 0, 0);
	a = ft_printf("ft_: @moulitest2: [%.o %.0o]\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_o_spec2 failed_______\033[0m\n\n"));
	++done;
}

void	basic_o_spec3(void)
{
	int	a;
	int	b;
	b = printf("pri: @moulitest3: [%5.o %5.0o]\n", 0, 0);
	a = ft_printf("ft_: @moulitest3: [%5.o %5.0o]\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_o_spec3 failed_______\033[0m\n\n"));
	++done;
}

void	basic_o_spec4(void)
{
	int	a;
	int	b;
	b = printf("pri: @moulitest: [%#.o %#.0o]\n", 0, 0);
	a = ft_printf("ft_: @moulitest: [%#.o %#.0o]\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_o_spec4 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec(void)
{
	int	a;
	int	b;
	b = printf("pri: %+d\n", 42);
	a = ft_printf("ft_: %+d\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec1(void)
{
	int	a;
	int	b;
	b = printf("pri: %++d\n", 42);
	a = ft_printf("ft_: %++d\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec1 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec3(void)
{
	int	a;
	int	b;
	b = printf("pri: %5d\n", -42);
	a = ft_printf("ft_: %5d\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec3 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec4(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-+10.5d]\n", 4242);
	a = ft_printf("ft_: [%-+10.5d]\n", 4242);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec4 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec5(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-5d]\n", -42);
	a = ft_printf("ft_: [%-5d]\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec5 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec6(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-5d]\n", -42);
	a = ft_printf("ft_: [%-5d]\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec6 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec7(void)
{
	int	a;
	int	b;
	b = printf("pri: [%0+5d]\n", -42);
	a = ft_printf("ft_: [%0+5d]\n", -42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec7 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec9(void)
{
	int	a;
	int	b;
	b = printf("pri: %.d %.0d\n", 0, 0);
	a = ft_printf("ft_: %.d %.0d\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec9 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec10(void)
{
	int	a;
	int	b;
	b = printf("pri: %ld\n", 36854775807);
	a = ft_printf("ft_: %ld\n", 36854775807);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec10 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test(void)
{
	int	a;
	int	b;
	b = printf("pri: aa%%db\n");
	a = ft_printf("ft_: aa%%db\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test1(void)
{
	long	a;
	long	b;
	b = printf("pri: %lo, %lo\n", 0ul, 4294967295);
	a = ft_printf("ft_: %lo, %lo\n", 0ul, 4294967295);
	printf("\nret: %d \n", (int)b);
	printf("ret: %d \n", (int)a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test1 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test2(void)
{
	long long	a;
	long long	b;
	b = printf("pri: %lo, %lo\n", 0ul, 9223372036854775807);
	a = ft_printf("ft_: %lo, %lo\n", 0ul, 9223372036854775807);
	printf("\nret: %d \n", (int)b);
	printf("ret: %d \n", (int)a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test2 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test3(void)
{
	unsigned short	a;
	unsigned short	b;
	b = printf("pri: %o, %o\n", 0, 65535);
	a = ft_printf("ft_: %o, %o\n", 0, 65535);
	printf("\nret: %d \n", (int)b);
	printf("ret: %d \n", (int)a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test3 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test4(void)
{
	int	a;
	int	b;
	b = printf("pri: %o, %o\n", 0, 255);
	a = ft_printf("ft_: %o, %o\n", 0, 255);
	printf("\nret: %d \n", (int)b);
	printf("ret: %d \n", (int)a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test4 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test6(void)
{
	int	a;
	int	b;
	b = printf("pri: %#o\n", 0);
	a = ft_printf("ft_: %#o\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test6 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test7(void)
{
	int	a;
	int	b;
	b = printf("pri: {% 03d}\n", 0);
	a = ft_printf("ft_: {% 03d}\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test7 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test8(void)
{
	int	a;
	int	b;
	b = printf("pri: %15.4d\n", -424242);
	a = ft_printf("ft_: %15.4d\n", -424242);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test8 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test9(void)
{
	int	a;
	int	b;
	b = printf("pri: %.4s\n", "42");
	a = ft_printf("ft_: %.4s\n", "42");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test9 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test11(void)
{
	int	a;
	int	b;
	int c = 10;
	int d = 11;
	b = printf("pri: %p, %p\n", &c, &d);
	a = ft_printf("ft_: %p, %p\n", &c, &d);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test11 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test12(void)
{
	int	a;
	int	b;
	b = printf("pri: %o, %o\n", -42, 42);
	a = ft_printf("ft_: %o, %o\n", -42, 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test12 failed_______\033[0m\n\n"));
	++done;
}

/* void	mouli_test14(void)
{
	int	a;
	int	b;
	b = printf("pri: %*.*d\n", 0, 3, 0);
	a = ft_printf("ft_: %*.*d\n", 0, 3, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test14 failed_______\033[0m\n\n"));
	++done;
} */

void	mouli_test15(void)
{
	int	a;
	int	b;
	b = printf("pri: {%3d}\n", 10);
	a = ft_printf("ft_: {%3d}\n", 10);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test15 failed_______\033[0m\n\n"));
	++done;
}

void	random_leo1(void)
{
	int	a;
	int	b;
	b = printf("pri: %#08.15x-\n", 42);
	a = ft_printf("ft_: %#08.15x-\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_leo1 failed_______\033[0m\n\n"));
	++done;
}

void	random_leo2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-10.5o]\n", 2500);
	a = ft_printf("ft_: [%-10.5o]\n", 2500);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_leo2 failed_______\033[0m\n\n"));
	++done;
}

void	random_leo4(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#08.15x]\n", 42);
	a = ft_printf("ft_: [%#08.15x]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_leo4 failed_______\033[0m\n\n"));
	++done;
}

void	random_jeff(void)
{
	int	a;
	int	b;
	b = printf("pri: %.1f\n", 2.25);
	a = ft_printf("ft_: %.1f\n", 2.25);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_jeff failed_______\033[0m\n\n"));
	++done;
}

void	more_mouli1(void)
{
	int	a;
	int	b;
	b = printf("pri: %.u, %.0u\n", 0, 0);
	a = ft_printf("ft_: %.u, %.0u\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_mouli1 failed_______\033[0m\n\n"));
	++done;
}

void	more_mouli2(void)
{
	int	a;
	int	b;
	b = printf("pri: %5.4s?\n", "");
	a = ft_printf("ft_: %5.4s?\n", "");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_mouli2 failed_______\033[0m\n\n"));
	++done;
}

void	more_mouli4(void)
{
	int	a;
	int	b;
	b = printf("pri: {%#.5x}\n", 1);
	a = ft_printf("ft_: {%#.5x}\n", 1);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_mouli4 failed_______\033[0m\n\n"));
	++done;
}

void	more_random_floats(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#33.3f]\n", 0.0005);
	a = ft_printf("ft_: [%#33.3f]\n", 0.0005);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_floats failed_______\033[0m\n\n"));
	++done;
}

void	more_random_floats1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#-10.22f]\n", 1.9999999999999);
	a = ft_printf("ft_: [%#-10.22f]\n", 1.9999999999999);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_floats1 failed_______\033[0m\n\n"));
	++done;
}

void	more_random_floats2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#11.0f]\n", 1.5);
	a = ft_printf("ft_: [%#11.0f]\n", 1.5);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_floats2 failed_______\033[0m\n\n"));
	++done;
}

void	more_random_floats3(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#+1.10f]\n", 2.5);
	a = ft_printf("ft_: [%#+1.10f]\n", 2.5);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_floats3 failed_______\033[0m\n\n"));
	++done;
}

void	more_random_binary(void)
{
	int	a;
	int	b;
	b = printf("pri: [%+-d]\n", 42);
	a = ft_printf("ft_: [%+-d]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_binary failed_______\033[0m\n\n"));
	++done;
}

void	more_random_jeff2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%c]\n", 0);
	a = ft_printf("ft_: [%c]\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_jeff2 failed_______\033[0m\n\n"));
	++done;
}

void	ptf0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%0-8.5d]\n", 34); //0 flag is ignored when -, put that fix in
	a = ft_printf("ft_: [%0-8.5d]\n", 34);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pft0 failed_______\033[0m\n\n"));
	++done;
}

void	ptf(void)
{
	int	a;
	int	b;
	b = printf("pri: [%7.15s]\n", "hello");
	a = ft_printf("ft_: [%7.15s]\n", "hello");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pft failed_______\033[0m\n\n"));
	++done;
}

void	ptf1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%17s]\n", NULL);
	a = ft_printf("ft_: [%17s]\n", NULL);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pft1 failed_______\033[0m\n\n"));
	++done;
}

void	ptf2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%18s]\n", "hello yo");
	a = ft_printf("ft_: [%18s]\n", "hello yo");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pft2 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings(void)
{
	int	a;
	int	b;
	b = printf("pri: %10s is a string\n", "this");
	a = ft_printf("ft_: %10s is a string\n", "this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings1(void)
{
	int	a;
	int	b;
	b = printf("pri: %.2s is a string\n", "this");
	a = ft_printf("ft_: %.2s is a string\n", "this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings1 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings2(void)
{
	int	a;
	int	b;
	b = printf("pri: %-10s is a string\n", "this");
	a = ft_printf("ft_: %-10s is a string\n", "this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings2 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings3(void)
{
	int	a;
	int	b;
	b = printf("pri: %5.2s is a string\n", "wazzup");
	a = ft_printf("ft_: %5.2s is a string\n", "wazzup");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings3 failed_______\033[0m\n\n"));
	++done;
}
/*
pri:       is a string
ft_:    00p is a string */

void	basic_strings4(void)
{
	int	a;
	int	b;
	b = printf("pri: %5.2s is a string\n", "this");
	a = ft_printf("ft_: %5.2s is a string\n", "this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings4 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings5(void)
{
	int	a;
	int	b;
	b = printf("pri: %-.2s is a string\n", "this");
	a = ft_printf("ft_: %-.2s is a string\n", "this");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings5 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings6(void)
{
	int	a;
	int	b;
	b = printf("pri: %-10s is a string\n", "");
	a = ft_printf("ft_: %-10s is a string\n", "");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings6 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings7(void)
{
	int	a;
	int	b;
	b = printf("pri: %-15.2s is a string\n", "asdasdasdasdasdsdasdasdsadassd");
	a = ft_printf("ft_: %-15.2s is a string\n", "asdasdasdasdasdsdasdasdsadassd");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings7 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings8(void)
{
	int	a;
	int	b;
	b = printf("pri: %s is a string\n", "NULL");
	a = ft_printf("ft_: %s is a string\n", "NULL");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings8 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings9(void)
{
	int	a;
	int	b;
	b = printf("pri: %s is %s a string\n", "", "string");
	a = ft_printf("ft_: %s is %s a string\n", "", "string");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings9 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hash4(void)
{
	int	a;
	int	b;
	b = printf("pri: %#-8x\n", 144);
	a = ft_printf("ft_: %#-8x\n", 144);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash4 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hexs10(void)
{
	int	a;
	int	b;
	b = printf("pri: @moulitest: %.x %.0x]\n", 0, 0);
	a = ft_printf("ft_: @moulitest: %.x %.0x]\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hexs10 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hexs11(void)
{
	int	a;
	int	b;
	b = printf("pri: @moulitest: [%#8xtjo]\n", 42);
	a = ft_printf("ft_: @moulitest: [%#8xtjo]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hexs11 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings10(void)
{
	int	a;
	int	b;
	b = printf("pri:%s %s\n", NULL, "string");
	a = ft_printf("ft_:%s %s\n", NULL, "string");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings10 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings11(void)
{
	int	a;
	int	b;
	b = printf("pri: %.4s is a string\n", "");
	a = ft_printf("ft_: %.4s is a string\n", "");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings11 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings12(void)
{
	int	a;
	int	b;
	b = printf("pri: %-.2s is a string\n", "");
	a = ft_printf("ft_: %-.2s is a string\n", "");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings12 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings13(void)
{
	int	a;
	int	b;
	b = printf("pri:@moulitest1: %s\n", NULL);
	a = ft_printf("ft_:@moulitest1: %s\n", NULL);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings13 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings14(void)
{
	int	a;
	int	b;
	b = printf("pri: %.s\n", "hello");
	a = ft_printf("ft_: %.s\n", "hello");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings14 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings15(void)
{
	int	a;
	int	b;
	b = printf("pri: %.0s\n", "hello");
	a = ft_printf("ft_: %.0s\n", "hello");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings15 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings16(void)
{
	int	a;
	int	b;
	b = printf("pri: %7.5s\n", "yolo");
	a = ft_printf("ft_: %7.5s\n", "yolo");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings16 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings17(void)
{
	int	a;
	int	b;
	b = printf("pri: %-7.5s\n", "yolo");
	a = ft_printf("ft_: %-7.5s\n", "yolo");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings17 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings18(void)
{
	int	a;
	int	b;
	b = printf("pri: [%7.7s %.s]\n", "hello", NULL);
	a = ft_printf("ft_: [%7.7s %.s]\n", "hello", NULL);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings18 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings19(void)
{
	int	a;
	int	b;
	b = printf("pri: %3.7s %7.s\n", "hello", "world");
	a = ft_printf("ft_: %3.7s %7.s\n", "hello", "world");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings19 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings20(void)
{
	int	a;
	int	b;
	b = printf("pri: %1.s %8.s]\n", "hello", "hej");
	a = ft_printf("ft_: %1.s %8.s]\n", "hello", "hej");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings20 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings21(void)
{
	int	a;
	int	b;
	b = printf("pri: %-16s\n", NULL);
	a = ft_printf("ft_: %-16s\n", NULL);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings21 failed_______\033[0m\n\n"));
	++done;
}

void	basic_strings22(void)
{
	int	a;
	int	b;
	b = printf("pri: %4.5s %-10.8s\n", "hey", NULL);
	a = ft_printf("ft_: %4.5s %-10.8s\n", "hey", NULL);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_strings22 failed_______\033[0m\n\n"));
	++done;
}

void	ptf_d(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#18.3o]\n", -8369);
	a = ft_printf("ft_: [%#18.3o]\n", -8369);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______ptf_d failed_______\033[0m\n\n"));
	++done;
}

void	ptf_d1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-010.15o]\n", -216);
	a = ft_printf("ft_: [%-010.15o]\n", -216);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______ptf_d1 failed_______\033[0m\n\n"));
	++done;
}

void	ptf_d2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%28.3d]\n", 8377);
	a = ft_printf("ft_: [%28.3d]\n", 8377);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______ptf_d2 failed_______\033[0m\n\n"));
	++done;
}

void	ptf_d3(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#08.23x]\n", 8375);
	a = ft_printf("ft_: [%#08.23x]\n", 8375);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______ptf_d3 failed_______\033[0m\n\n"));
	++done;
}

void	ptf_d4(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#0-18.3X]\n", 75);
	a = ft_printf("ft_: [%#0-18.3X]\n", 75);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______ptf_d4 failed_______\033[0m\n\n"));
	++done;
}

void	binary_bonus(void)
{
	int	a;
	int	b;
	b = printf("pri: 1000001\n");
	a = ft_printf("ft_: %b\n", 65);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______binary_bonus failed_______\033[0m\n\n"));
	++done;
}

void	binary_bonus1(void)
{
	int	a;
	int	b;
	b = printf("pri: 1000011\n");
	a = ft_printf("ft_: %b\n", 67);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______binary_bonus1 failed_______\033[0m\n\n"));
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
		assert(printf("\033[1;31m _______test_mindfuck_simpleminus failed_______\033[0m\n\n"));
	++done;
}

void	pro_test_bi2(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: [%013%] binary\n");
	a = ft_printf("ft_: [%013%] binary\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test_bi2 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final(void)
{
	int	a;
	int	b;
	b = printf("pri: %15.4i\n", -424242);
	a = ft_printf("ft_: %15.4i\n", -424242);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%+u]\n", 4294967295);
	a = ft_printf("ft_: [%+u]\n", 4294967295);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final1 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%lf]\n", 1.42);
	a = ft_printf("ft_: [%lf]\n", 1.42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final2 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final3(void)
{
	int	a;
	int	b;
	b = printf("pri: [%llo, %llo]\n", 0, 18446744073709551615);
	a = ft_printf("ft_: [%llo, %llo]\n", 0, 18446744073709551615);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final3 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final6(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.1f]\n", -2.95);
	a = ft_printf("ft_: [%.1f]\n", -2.95);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final6 failed_______\033[0m\n\n"));
	++done;
}

void	pro_test_leo(void)
{
	int	a = 429;
	int	b = 429;
	b = printf("pri: [%-+15d] show\n", 567876);
	a = ft_printf("ft_: [%-+15d] show\n", 567876);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______pro_test_leo failed_______\033[0m\n\n"));
	++done;
}

void	random_leo(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#08.5o]]\n", 444);
	a = ft_printf("ft_: [%#08.5o]]\n", 444);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_leo failed_______\033[0m\n\n"));
	++done;
}

void	more_random_leo8(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#08.5x]\n", 42);
	a = ft_printf("ft_: [%#08.5x]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______more_random_leo8 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final4(void)
{
	int	a;
	int	b;
	b = printf("pri: [%+018f]\n", 255.33);
	a = ft_printf("ft_: [%+018f]\n", 255.33);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final4 failed_______\033[0m\n\n"));
	++done;
}

void	mouli_test_final5(void)
{
	int	a;
	int	b;
	b = printf("pri: [%+011.3f]\n", 123.05);
	a = ft_printf("ft_: [%+011.3f]\n", 123.05);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______mouli_test_final5 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec8(void)
{
	int	a;
	int	b;
	b = printf("pri: [%013.2d]\n", 0);
	a = ft_printf("ft_: [%013.2d]\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec8 failed_______\033[0m\n\n"));
	++done;
}

void	basic_d_spec2(void)
{
	int	a;
	int	b;
	b = printf("pri: %05d\n", 42);
	a = ft_printf("ft_: %05d\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_d_spec2 failed_______\033[0m\n\n"));
	++done;
}

void	random_proc(void)
{
	int	a;
	int	b;
	b = printf("pri: %+8%\n");
	a = ft_printf("ft_: %+8%\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______random_proc failed_______\033[0m\n\n"));
	++done;
}

void	test_basic1(void)
{
	int	a;
	int	b;
	b = printf("pri: %-5%\n");
	a = ft_printf("ft_: %-5%\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic1 failed_______\033[0m\n\n"));
	++done;
}

void	test_basic0(void)
{
	int	a;
	int	b;
	b = printf("pri: %05%\n");
	a = ft_printf("ft_: %05%\n");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_basic0 failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-*.*s]\n", -7, 3, "yolo");
	a = ft_printf("ft_: [%-*.*s]\n", -7, 3, "yolo");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard0 failed_______\033[0m\n\n"));
	++done;
}



void	crazy_big_float(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.647f]\n", 13.13131313131313313);
	a = ft_printf("ft_: [%.647f]\n", 13.13131313131313313);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______crazy_big_float failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_i(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.*i]\n", -6, -3);
	a = ft_printf("ft_: [%.*i]\n", -6, -3);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_i failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_i1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%0*i]\n", -7, -54);
	a = ft_printf("ft_: [%0*i]\n", -7, -54);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_i1 failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_str0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.*s]\n", -3, "hello");
	a = ft_printf("ft_: [%.*s]\n", -3, "hello");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_str0 failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_str1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-*.*s]\n", -7, -3, "yolo");
	a = ft_printf("ft_: [%-*.*s]\n", -7, -3, "yolo");
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_str1 failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_ran0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.*u]\n", -1, 0);
	a = ft_printf("ft_: [%.*u]\n", -1, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_ran0 failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard_ran1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%.*o]\n", -1, 0);
	a = ft_printf("ft_: [%.*o]\n", -1, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard_ran1 failed_______\033[0m\n\n"));
	++done;
}

void	test_satu_test0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%-+31.5d]\n", -392082);
	a = ft_printf("ft_: [%-+31.5d]\n", -392082);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_satu_test0 failed_______\033[0m\n\n"));
	++done;
}

void	test_satu_test1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%#010Lf]\n", 003.141593l);
	a = ft_printf("ft_: [%#010Lf]\n", 003.141593l);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_satu_test1 failed_______\033[0m\n\n"));
	++done;
}

void	test_satu_test2(void)
{
	int	a;
	int	b;
	b = printf("pri: [%5.0d]\n", 42);
	a = ft_printf("ft_: [%5.0d]\n", 42);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_satu_test2 failed_______\033[0m\n\n"));
	++done;
}

void	test_last_basic(void)
{
	int	a;
	int	b;
	b = printf("pri: [%5.0d]\n", 0);
	a = ft_printf("ft_: [%5.0d]\n", 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_last_basic failed_______\033[0m\n\n"));
	++done;
}

void	test_wildcard1(void)
{
	int	a;
	int	b;
	b = printf("pri: [%*.*d]\n", 7, -13, 4242);
	a = ft_printf("ft_: [%*.*d]\n", 7, -13, 4242);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_wildcard1 failed_______\033[0m\n\n"));
	++done;
}

void	test_more_satu(void)
{
	int	a;
	int	b;
	b = printf("pri: [%010u]\n", 0001375622);
	a = ft_printf("ft_: [%010u]\n", 0001375622);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_more_satu failed_______\033[0m\n\n"));
	++done;
}

void	test_evals0(void)
{
	int	a;
	int	b;
	b = printf("pri: [%10.0x]\n", 1233);
	a = ft_printf("ft_: [%10.0x]\n", 1233);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______test_evals0 failed_______\033[0m\n\n"));
	++done;
}

void	basic_hash5(void)
{
	int	a;
	int	b;
	b = printf("pri: [%5.x %5.0x]\n", 0, 0);
	a = ft_printf("ft_: [%5.x %5.0x]\n", 0, 0);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\033[1;31m _______basic_hash5 failed_______\033[0m\n\n"));
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
	test_address();
	test_asterix_with_str();
	test_asterix_with_int();
	test_width_single();
	test_width_multi();
	test_width_multi2();
 	test_precision();
 	test_precision_1();
	test_mindfuck();
	test_mindfuck_minusminus();
 	test_mindfuck_minusminint();
	test_mindfuck_minusminint2();
	test_mindfuck_plus_craz();
	test_mindfuck_plus_craz2();
	test_mindfuck_plus_craz3();
	test_mindfuck_plus_craz4();
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
	test_flag_zero_with_pre6();
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
	test_procentage();
	test_flag_space_minus();
	test_flag_space();
	test_float0();
	test_float1();
	test_float2();
	test_float3();
	test_float4();
	test_float5();
	test_float6();
	test_float7();
	test_float8();
	test_float9();
	test_float10();
 	test_float11();
	test_float12();
 	test_basic2();
	test_basic3();
	test_basic4();
	pro_test();
	pro_test1();
	pro_test2();
	pro_test33();
	test_mindfuck_minus();
	test_basic5();
	pro_test3();
	basic_simple_proc();
	basic_plus_uint();
	basic_valt();
	pro_test4();
	basic_hash();
	basic_hash1();
	basic_hash2();
	test_basic6();
	basic_hash3();
 	basic_hash4();
	basic_hexs10();
	basic_hexs11();
	basic_char1();
	basic_char2();
	basic_char3();
	basic_o_spec();
	basic_o_spec1();
	basic_o_spec2();
	basic_o_spec3();
	basic_o_spec4();
	basic_d_spec();
	basic_d_spec1();
	basic_d_spec3();
	basic_d_spec4();
	basic_d_spec5();
	basic_d_spec6();
	basic_d_spec7();
	basic_d_spec9();
	basic_d_spec10();
	mouli_test();
	mouli_test1();
	mouli_test2();
	mouli_test3();
	mouli_test4();
	mouli_test6();
	mouli_test7();
	mouli_test8();
	mouli_test9();
	mouli_test11();
	mouli_test12();
	random_leo1();
	random_leo2();
	random_leo4();
	random_jeff();
	more_mouli1();
	more_mouli2();
	more_mouli4();
	more_random_floats();
	more_random_floats1();
	more_random_floats2();
	more_random_floats3();
	more_random_jeff2();
 	ptf0();
	ptf();
	ptf1();
	ptf2();
	basic_strings();
	basic_strings1();
	basic_strings2();
	basic_strings3();
	basic_strings4();
	basic_strings5();
	basic_strings6();
	basic_strings7();
	basic_strings8();
	basic_strings9();
	basic_strings10();
	basic_strings11();
	basic_strings12();
	basic_strings13();
	basic_strings14();
	basic_strings15();
	basic_strings16();
	basic_strings17();
	basic_strings18();
	basic_strings19();
	basic_strings20();
	basic_strings21();
	basic_strings22();
	ptf_d();
	ptf_d1();
	ptf_d2();
	ptf_d3();
	ptf_d4();
	binary_bonus();
	binary_bonus1();
	test_mindfuck_simpleminus();
	pro_test_bi2();		//fix in school
	mouli_test_final();
	mouli_test_final1();
	mouli_test_final2();
	mouli_test_final3();
	mouli_test_final6();
	pro_test_leo();
	random_leo();
	more_random_leo8();
	mouli_test_final4();
	mouli_test_final5();
	basic_d_spec8();
	basic_d_spec2();
	random_proc();
	test_basic1();
	test_basic0();
	test_wildcard0();
	crazy_big_float();
	test_wildcard_i();
	test_wildcard_i1();
	test_wildcard_str0();
	test_wildcard_str1();
	test_wildcard_ran0();
	test_wildcard_ran1();
	test_satu_test0();
	test_satu_test1();
	test_satu_test2();
	test_last_basic();
	test_wildcard1();
	test_more_satu();
	test_evals0();
	basic_hash5();

	if (tests == done)
		printf("\n\033[1;32m%d\033[0m/\033[1;32m%d\033[0m completed\n", tests, done);
	else
		printf("\n\033[1;31m%d\033[0m/\033[1;32m%d\033[0m completed\n", tests, done);
	return (0);
}
