/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:14:49 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:47:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"
#include "length.h"

void		putnbr_printf(int n);
void		set_lengths_prf(long long num, t_length *l, t_flags *f, int base);
static void	put_paddings(t_length *length, t_flags *flags);
static void	put_precision(size_t count);
void		put_uint_printf(unsigned int num);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

int	print_uint_printf(unsigned int num, t_flags *flags)
{
	t_length	length;

	set_lengths_prf(num, &length, flags, 10);
	if (flags->left_align == 0)
		put_paddings(&length, flags);
	put_precision(length.precision_padding);
	if (length.value != 0)
		put_uint_printf(num);
	if (flags->left_align == 1)
		put_paddings(&length, flags);
	return (length.total);
}

static void	put_paddings(t_length *length, t_flags *flags)
{
	size_t	count;

	if (length->space == 0)
		return ;
	count = length->space;
	if (flags->zero_padding == F_ZERO_PADDING)
		while (count-- > 0)
			ft_write_printf("0", 1);
	if (flags->zero_padding != F_ZERO_PADDING)
		while (count-- > 0)
			ft_write_printf(" ", 1);
}

static void	put_precision(size_t count)
{
	if (count == 0)
		return ;
	while (count-- > 0)
		ft_write_printf("0", 1);
}
