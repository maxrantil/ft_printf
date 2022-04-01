/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_getit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/01 15:18:11 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	get_it(t_var *st)
{
	size_t	c_single;
	size_t	ret;

	c_single = 0;
	ret = 0;
	st->width_check = 1;
	while (ft_isdigit(*st->fmt) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			ret = *st->fmt - 48;
		else
			ret = ret * 10 + (*st->fmt - 48);
		st->fmt++;
	}
	return (ret);
}