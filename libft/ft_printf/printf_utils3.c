/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:38:06 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:49:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	digit_of_address_printf(unsigned long long num)
{
	unsigned long long	dummy;
	size_t				digit;

	dummy = 16;
	digit = 1;
	while (dummy - 1 < num)
	{
		dummy *= 16;
		digit++;
	}
	return (digit);
}

ssize_t	ft_write_printf(const void *buf, size_t nbyte)
{
	static ssize_t	memory = 0;
	ssize_t			output;

	if (buf == NULL && nbyte == 0)
	{
		output = memory;
		memory = 0;
		return (output);
	}
	output = write(1, buf, nbyte);
	if (memory >= 0)
		memory = output;
	return (output);
}
