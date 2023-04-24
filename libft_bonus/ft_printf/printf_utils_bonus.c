/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:09:07 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:20:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"

int	is_passable_character_printf(const char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i'
		&& c != 'u' && c != 'x' && c != 'X' && c != '%' && c != '\0')
		return (1);
	return (0);
}

int	is_flag_character_printf(const char c)
{
	if (c != '-' && c != '0' && c != '#' && c != ' ' && c != '+')
		return (0);
	return (1);
}

void	set_flags_printf(const char c, t_flags *flags)
{
	if (c == '-')
	{
		flags->left_align = 1;
		flags->zero_padding = F_NO_PADDING;
	}
	if (c == '0')
		flags->zero_padding = F_ZERO_PADDING;
	if (c == '#')
		flags->base_visible = 1;
	if (c == ' ')
		flags->sign = F_SIGN_SPACE;
	if (c == '+')
		flags->sign = F_SIGN_PLUS;
}

int	is_there_sign_printf(long long num, t_flags *flags)
{
	if (flags->base_visible == 1 && num == 0)
		return (0);
	if (flags->base_visible == 1)
		return (2);
	if (flags->sign == F_NO_SIGN && num >= 0)
		return (0);
	return (1);
}
