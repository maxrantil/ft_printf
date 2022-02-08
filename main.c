/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 21:37:47 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <assert.h>

static unsigned int tests;
static unsigned int done;

void mix_ez(void)
{
	int	a;
	int	b;
	a = ft_printf("test%u %d %%this %i %s %c %c \n", -3, 4, 1, "hej", 'a', 'b');
	b = printf("test%u %d %%this %i %s %c %c \n", -3, 4, 1, "hej", 'a', 'b');
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez failed_______\x1b[0m\n\n"));
	++done;
}

void	test_oct_zero(void)
{
	int	a;
	int	b;
	a = ft_printf("oct: %o\n", 0);
	b = printf("oct: %o\n", 0);
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
	a = ft_printf("oct: %o\n", 123432);
	b = printf("oct: %o\n", 123432);
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
	a = ft_printf("hex: %X \n", 1234554321);
	b = printf("hex: %X \n", 1234554321);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex failed_______\x1b[0m\n\n"));
	++done;
}

void	test_dec(void)
{
	int	a;
	int	b;
	printf("test_dec:\n");
	printf("ft_printf:\n");
	a = ft_printf("decimal  %d\n", 32456);
	printf("ret:	 %d\n", a);
	printf("printf:\n");
	b = printf("decimal  %d\n", 32456);
	printf("ret:	 %d\n", b);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n _______test_dec failed_______\x1b[0m\n\n"));
	++done;
}

int	main(void)
{
	mix_ez();
	test_oct_zero();
	test_oct();
	test_hex();
	test_dec();

	printf("%d/%d completed\n", tests, done);
	return (0);
}