/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:57:31 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);
static size_t	ft_strnlen(const char *s, size_t size);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	int		index;

	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	needle_size = ft_strlen(needle);
	len = ft_strnlen(haystack, len);
	while (len-- >= needle_size)
	{
		index = 0;
		while (needle[index] && haystack[index] == needle[index])
			index++;
		if (needle[index] == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
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
