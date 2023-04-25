/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:04:46 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:50:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_nbr(char *buffer, size_t buffer_len);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

void	put_uint_printf(unsigned int num)
{
	char		buffer[10];
	char		*ptr;

	ptr = buffer;
	if (num == 0)
		*ptr++ = '0';
	while (num)
	{
		*ptr++ = num % 10 + '0';
		num /= 10;
	}
	write_nbr(buffer, ptr - buffer);
}

static void	write_nbr(char *buffer, size_t buffer_len)
{
	char	str[10];
	char	*ptr;

	ptr = str;
	buffer += buffer_len;
	while (buffer_len--)
		*ptr++ = *--buffer;
	ft_write_printf(str, ptr - str);
}
