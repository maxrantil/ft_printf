/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:13:19 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/04 16:45:36 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		if (src[i] == '\0')
			dst[j] = '\0';
		else
		{
			dst[j] = src[i];
			i++;
		}
		j++;
	}
	return (dst);
}
