/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/04 11:58:59 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("test%    d this %    i %s %c %c \n", 4, 1, "hej", 'a', 'b');
	b = printf("test%    d this %    i %s %c %c \n", 4, 1, "hej", 'a', 'b');
	printf("\nft_printf ret\t= %d\n", a);
	printf("printf ret\t= %d\n", b);
	return (0);
}

/* int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("test%d", 4);
	b = printf("test%d", 4);
	printf("\nft_printf ret\t= %d\n", a);
	printf("printf ret\t= %d\n", b);
	return (0);
} */

//line 108 fixex second main, but fucked up first main. fix that tomorrow