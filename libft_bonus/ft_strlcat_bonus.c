/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:46:39 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);
static size_t	ft_strnlen(const char *s, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;

	src_size = ft_strlen(src);
	dest_size = ft_strnlen(dest, size);
	if (size <= dest_size)
		return (src_size + size);
	dest += dest_size;
	size -= dest_size;
	while (*src && --size)
		*dest++ = *src++;
	*dest = 0;
	return (src_size + dest_size);
}

static size_t	ft_strnlen(const char *s, size_t size)
{
	char	*ptr;

	ptr = (char *)s;
	while (size && *ptr)
	{
		size--;
		ptr++;
	}
	return (ptr - s);
}
