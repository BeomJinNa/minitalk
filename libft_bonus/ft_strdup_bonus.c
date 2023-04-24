/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:18:44 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, size + 1);
	return (dest);
}
