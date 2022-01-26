/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:05:00 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/16 19:32:31 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*sj;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	sj = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sj)
		return (NULL);
	while (s1[i])
	{
		sj[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sj[i] = s2[j];
		i++;
		j++;
	}
	sj[i] = '\0';
	return (sj);
}
