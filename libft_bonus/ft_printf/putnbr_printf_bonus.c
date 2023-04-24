/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:04:46 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:20:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_nbr(char *buffer, size_t buffer_len);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

void	putnbr_printf(int n)
{
	char		buffer[11];
	long long	num;
	char		*ptr;

	num = n;
	ptr = buffer + 1;
	*buffer = 0;
	if (num < 0)
	{
		*buffer = '-';
		num = -num;
	}
	if (num == 0)
		*ptr++ = '0';
	while (num)
	{
		*ptr++ = num % 10 + '0';
		num /= 10;
	}
	ft_write_nbr(buffer, ptr - buffer);
}

static void	ft_write_nbr(char *buffer, size_t buffer_len)
{
	char	str[11];
	char	*ptr;

	ptr = str;
	if (*buffer)
		*ptr++ = *buffer;
	buffer += buffer_len;
	while (--buffer_len)
		*ptr++ = *--buffer;
	ft_write_printf(str, ptr - str);
}
