/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:38:06 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:52:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "length.h"

int			is_there_sign_printf(long long num, t_flags *flags);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

size_t	min_len_printf(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	return (a);
}

size_t	max_len_printf(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	ft_putstrn_printf(char *s, size_t buffer)
{
	char	*ptr;

	ptr = s;
	while (*ptr && (size_t)(ptr - s) < buffer)
		ptr++;
	ft_write_printf(s, ptr - s);
}

size_t	digit_of_number_printf(long long num, int base)
{
	long long	dummy;
	size_t		digit;

	if (base < 2)
		return (0);
	dummy = base;
	digit = 1;
	if (num < 0)
		num = -num;
	while (dummy - 1 < num)
	{
		dummy *= base;
		digit++;
		if (dummy < 0)
			return (0);
	}
	return (digit);
}

void	set_lengths_prf(long long num, t_length *l, t_flags *flags, int base)
{
	l->value = digit_of_number_printf(num, base);
	if (num == 0 && flags->zero_padding == F_ZERO_PRECISION)
		l->value = 0;
	l->precision_padding = 0;
	if (flags->precision > l->value)
		l->precision_padding = flags->precision - l->value;
	l->number = max_len_printf(flags->precision, l->value);
	l->number += is_there_sign_printf(num, flags);
	l->total = max_len_printf(flags->width, l->number);
	l->space = l->total - l->number;
}
