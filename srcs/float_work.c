/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:54 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/02 16:21:23 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	nine_rouning(char *mantissa, int i, t_var *st)
{
	long long	new_unit;

	mantissa[--i] = '0';
	while (i-- && mantissa[i] == '9')
		mantissa[i] = '0';
	if (i >= 0)
		mantissa[i] += 1;
	else
	{
		new_unit = ft_atoi(st->hold_str);
		ft_strdel(&st->hold_str);
		pf_itoa_base(new_unit + 1, 10, st);
	}
}

static int	bankers_rounding(long double nbr, char last_digit, t_var *st)
{
	int	res;

	res = 0;
	nbr = (nbr - (long long)nbr);
	if (nbr > 0.5)
		res++;
	else if (nbr == 0.5)
		res = ((last_digit + 1 * st->sign) % 2 == 0);
	return (res);
}

static char	*join_unit_mant(char *mantissa, size_t x, t_var *st)
{
	char	*combo;
	int		i;
	int		j;

	j = 0;
	i = 0;
	combo = ft_strnew(ft_strlen(st->hold_str) + ft_strlen(mantissa) + 1);
	if (!combo)
		exit(1);
	while (st->hold_str[i])
		combo[j++] = st->hold_str[i++];
	if (st->precision || x == 6)
		combo[j++] = '.';
	i = 0;
	while (mantissa[i])
		combo[j++] = mantissa[i++];
	ft_strdel(&st->hold_str);
	ft_strdel(&mantissa);
	return (combo);
}

static char	*mant_to_a(long double nbr, t_var *st)
{
	char		*mantissa;
	int			i;
	size_t		x;
	int			round_up;

	i = 0;
	mantissa = ft_strnew(st->precision);
	x = 0;
	while (st->precision > x)
	{
		nbr *= 10;
		mantissa[i++] = ((long long)nbr % 10) + 48;
		nbr -= (long long)nbr;
		x++;
	}
	round_up = bankers_rounding(nbr, mantissa[i - 1], st);
	if (round_up == 1 && mantissa[i - 1] == '9')
		nine_rouning(mantissa, i, st);
	else
		mantissa[i - 1] += round_up;
	return (join_unit_mant(mantissa, x, st));
}

void	conv_float_str(long double nbr, t_var *st)
{
	int			round_up;
	long long	last_digit;

	st->sign = 1 - 2 * (nbr < 0 || (1 / nbr < 0 && nbr == 0));
	if (nbr < 0 || (1 / nbr < 0 && nbr == 0))
	{
		nbr *= -1;
		st->width -= (st->width > 0);
	}
	if (!st->precision && st->precision_flag)
	{
		last_digit = (long long)nbr % 10;
		round_up = bankers_rounding(nbr, last_digit + 48, st) * st->sign;
		pf_itoa_base((long long)nbr + round_up, 10, st);
	}
	else
	{
		pf_itoa_base((long long)nbr, 10, st);
		st->hold_str = mant_to_a(nbr, st);
	}
}