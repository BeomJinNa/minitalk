/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:07:56 by bena              #+#    #+#             */
/*   Updated: 2022/11/21 19:58:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size > src_size + 1)
		size = src_size + 1;
	ft_memcpy(dest, src, size - 1);
	*(dest + size - 1) = 0;
	return (src_size);
}
