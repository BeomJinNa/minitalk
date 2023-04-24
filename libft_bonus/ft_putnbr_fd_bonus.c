/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:04:46 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_nbr(char *buffer, size_t buffer_len, int fd);

void	ft_putnbr_fd(int n, int fd)
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
	ft_write_nbr(buffer, ptr - buffer, fd);
}

static void	ft_write_nbr(char *buffer, size_t buffer_len, int fd)
{
	char	str[11];
	char	*ptr;

	ptr = str;
	if (*buffer)
		*ptr++ = *buffer;
	buffer += buffer_len;
	while (--buffer_len)
		*ptr++ = *--buffer;
	write(fd, str, ptr - str);
}
