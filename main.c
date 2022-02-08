/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 16:31:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

/* int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("test%u %d %%this %i %s %c %c \n", -3, 4, 1, "hej", 'a', 'b');
	b = printf("test%u %d %%this %i %s %c %c \n", -3, 4, 1, "hej", 'a', 'b');
	printf("\nft_printf ret\t= %d\n", a);
	printf("printf ret\t= %d\n", b);
	return (0);
} */

int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("hex: %X \noct: %o\n", 1234554321, 10);
	ft_putchar('\n');
	b = printf("hex: %X \noct: %o\n", 1234554321, 10);
	printf("\nft_printf ret\t= %d\n", a);
	printf("printf ret\t= %d\n", b);
	return (0);
}

/* int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("test %     d\n", 32456);
	b = printf("test %     d\n", 32456);
	printf("\nft_printf ret\t= %d\n", a);
	printf("printf ret\t= %d\n", b);
	return (0);
} */

//line 108 fixex second main, but fucked up first main. fix that tomorrow