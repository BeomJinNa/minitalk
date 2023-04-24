/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:26:20 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:20:00 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags_printf(const char c, t_flags *flags);
int			is_flag_character_printf(const char c);
static int	put_result(char c, t_flags *flags);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

int	print_char_printf(char c, const char *ptr)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character_printf(*(++ptr)))
		set_flags_printf(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	return (put_result(c, &flags));
}

static int	put_result(char c, t_flags *flags)
{
	int	output;

	if (flags->width == 0)
		flags->width = 1;
	output = (flags->width)--;
	if (flags->left_align == 0)
		while ((flags->width)-- > 0)
			ft_write_printf(" ", 1);
	ft_write_printf(&c, 1);
	if (flags->left_align == 1)
		while ((flags->width)-- > 0)
			ft_write_printf(" ", 1);
	if (output < 1)
		return (1);
	return (output);
}
