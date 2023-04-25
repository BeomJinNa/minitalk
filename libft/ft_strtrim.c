/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:46:18 by bena              #+#    #+#             */
/*   Updated: 2022/11/23 21:36:11 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		is_in_set(char c, const char *set);
void			*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_i;
	char	*ptr_f;
	char	*str;

	ptr_i = (char *)s1;
	ptr_f = ptr_i;
	while (*ptr_f)
		ptr_f++;
	while (*ptr_i && is_in_set(*ptr_i, set))
		ptr_i++;
	while (--ptr_f >= ptr_i && is_in_set(*ptr_f, set))
		;
	str = (char *)malloc(sizeof(char) * ((ptr_f - ptr_i + 1) + 1));
	if (str == 0)
		return (0);
	*(str + (ptr_f - ptr_i + 1)) = 0;
	return ((char *)ft_memcpy(str, ptr_i, ptr_f - ptr_i + 1));
}

static int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}
