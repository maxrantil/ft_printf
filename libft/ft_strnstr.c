/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:37:08 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/17 20:01:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[j] && len)
	{
		while (haystack[j + i] == needle[i] && i < len)
		{
			i++;
			if (i == ft_strlen(needle))
				return (&((char *)haystack)[j]);
		}
		i = 0;
		len--;
		j++;
	}
	return (NULL);
}
