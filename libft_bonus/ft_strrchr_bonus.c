/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:12:08 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*s_memory;
	char	ch;

	ch = c;
	s_memory = 0;
	while (*s)
		if (*s++ == ch)
			s_memory = (char *)s - 1;
	if (ch == 0)
		return ((char *)s);
	return (s_memory);
}
