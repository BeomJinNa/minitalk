/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:36:42 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:34 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr_from;
	char	*ptr_to;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	ptr_to = str;
	ptr_from = (char *)s1;
	while (*ptr_from)
		*ptr_to++ = *ptr_from++;
	ptr_from = (char *)s2;
	while (*ptr_from)
		*ptr_to++ = *ptr_from++;
	*ptr_to = 0;
	return (str);
}
