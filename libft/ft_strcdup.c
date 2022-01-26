/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/10 16:13:45 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c, int n)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s1[i] && s1[i] != c)
	{
		i++;
		if (s1[i] == c)
		{
			if (n == 0)
				cpy = ft_strsub(s1, 0, i);
			else
				cpy = ft_strsub(s1, 0, i + 1);
			return (cpy);
		}
	}
	return (NULL);
}
