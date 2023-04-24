/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:03:58 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:23 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*address_src;
	unsigned char	*address_dst;

	if (src == 0 && dst == 0)
		return (0);
	address_src = (unsigned char *)src;
	address_dst = (unsigned char *)dst;
	if (address_src > address_dst)
		while (len--)
			*address_dst++ = *address_src++;
	else
	{
		while (len)
		{
			*(address_dst + len - 1) = *(address_src + len - 1);
			len--;
		}
	}
	return (dst);
}
