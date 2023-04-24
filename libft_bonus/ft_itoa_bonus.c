/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:37:53 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_get_a(char *buffer, size_t buffer_len);

char	*ft_itoa(int n)
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
	return (ft_get_a(buffer, ptr - buffer));
}

static char	*ft_get_a(char *buffer, size_t buffer_len)
{
	char	*str;
	char	*ptr;

	str = (char *)malloc(sizeof(char) * (buffer_len + (*buffer != 0)));
	if (str == 0)
		return (0);
	ptr = str;
	if (*buffer)
		*ptr++ = *buffer;
	*buffer = 0;
	buffer += buffer_len;
	while (buffer_len--)
		*ptr++ = *--buffer;
	return (str);
}
