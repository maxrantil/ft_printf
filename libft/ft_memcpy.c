/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:27 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 16:48:27 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_rest(unsigned char **dst,
		const unsigned char **src, size_t n)
{
	unsigned int	block;
	unsigned int	rest;

	block = n / sizeof(int);
	rest = n % sizeof(int);
	if (block)
		*(*(unsigned int **)dst)++ = *(*(const unsigned int **)src)++;
	if (rest / sizeof(short))
		*(*(unsigned short **)dst)++ = *(*(const unsigned short **)src)++;
	if (n % sizeof(short))
		*(*dst)++ = *(*src)++;
}

static void	cpy_blocks(unsigned char **dst,
		const unsigned char **src, size_t n)
{
	unsigned long		*d;
	const unsigned long	*s;

	d = (unsigned long *)*dst;
	s = (const unsigned long *)*src;
	*dst += n * sizeof(long);
	*src += n * sizeof(long);
	while (n--)
		*d++ = *s++;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		blocks;
	unsigned int		rest;

	if (n == 0 || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	blocks = n / sizeof(long);
	rest = n % sizeof(long);
	if (blocks)
		cpy_blocks(&d, &s, blocks);
	cpy_rest(&d, &s, rest);
	return (dst);
}
