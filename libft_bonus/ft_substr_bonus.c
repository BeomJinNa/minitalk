/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:42:26 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t size);

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr_from;
	char	*ptr_to;

	start = ft_strnlen(s, start);
	ptr_from = (char *)s + start;
	str = (char *)malloc(sizeof(char) * (ft_strnlen(ptr_from, len) + 1));
	if (str == 0)
		return (0);
	ptr_to = str;
	while (*ptr_from && len--)
		*ptr_to++ = *ptr_from++;
	*ptr_to = 0;
	return (str);
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
