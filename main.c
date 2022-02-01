/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 20:38:40 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	a;
	int	b;
	a = ft_printf("test%%%      d this %    i %s %c %c\n", 4, 1, "hej", 'a', 'b');
	b = printf("test%%%      d this %    i %s %c %c\n", 4, 1, "hej", 'a', 'b');
	printf("\nft_printf ret = %d\n", a);
	printf("\nprintf ret = %d\n", b);
	return (0);
}
