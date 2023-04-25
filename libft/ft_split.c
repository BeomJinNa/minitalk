/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:05:16 by bena              #+#    #+#             */
/*   Updated: 2022/11/25 17:48:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_countchr(const char *str, char c);
static size_t	ft_strclen(const char *str, char c);
static char		*ft_splndup(const char *str, size_t len);
static char		**remove_memory(char **address);

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	arr_size;
	size_t	token_size;
	char	**str;

	arr_size = ft_countchr(s, c) + 1;
	str_arr = (char **)malloc(sizeof(char *) * (arr_size + 1));
	if (str_arr == 0)
		return (0);
	*(str_arr + arr_size) = 0;
	str = str_arr;
	while (*s && *s == c)
		s++;
	while (arr_size--)
	{
		token_size = ft_strclen(s, c);
		*str = ft_splndup(s, token_size);
		if (*str++ == 0)
			return (remove_memory(str_arr));
		s += token_size;
		while (*s && *s == c)
			s++;
	}
	return (str_arr);
}

static size_t	ft_countchr(const char *str, char c)
{
	size_t	size;

	while (*str && *str == c)
		str++;
	if (*str == 0)
		return (-1);
	size = 0;
	while (*str)
	{
		if (*str == c)
			size++;
		while (*str == c)
			str++;
		if (*str == 0)
			return (--size);
		str++;
	}
	return (size);
}

static size_t	ft_strclen(const char *str, char c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr && *ptr != c)
		ptr++;
	return (ptr - str);
}

static char	*ft_splndup(const char *str, size_t len)
{
	char	*output;
	char	*ptr;

	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == 0)
		return (0);
	ptr = output;
	while (len--)
		*ptr++ = *str++;
	*ptr = 0;
	return (output);
}

static char	**remove_memory(char **address)
{
	char	**ptr;

	ptr = address;
	while (*ptr)
		free(*ptr++);
	free(address);
	return (0);
}
