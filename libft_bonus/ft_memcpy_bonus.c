/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:58:43 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:21:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*address_src;
	unsigned char	*address_dst;

	if (dst == 0 && src == 0)
		return (0);
	address_src = (unsigned char *)src;
	address_dst = (unsigned char *)dst;
	while (n--)
		*address_dst++ = *address_src++;
	return (dst);
}
