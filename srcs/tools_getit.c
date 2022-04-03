/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_getit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/03 20:43:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	get_it(t_ftprintf *data)
{
	size_t	c_single;
	size_t	ret;

	c_single = 0;
	ret = 0;
	data->width_check = 1;
	while (ft_isdigit(*data->fmt) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			ret = *data->fmt - 48;
		else
			ret = ret * 10 + (*data->fmt - 48);
		data->fmt++;
	}
	return (ret);
}