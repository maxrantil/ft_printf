/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:14:42 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/12 18:26:17 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
