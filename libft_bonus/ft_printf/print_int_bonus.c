/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:14:30 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:20:04 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags_bonus.h"

void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
void	set_flags_printf(const char c, t_flags *flags);
int		is_flag_character_printf(const char c);
int		print_dec_printf(int num, t_flags *flags);
int		print_hex_printf(int num, t_flags *flags, char conversion);
int		print_uint_printf(unsigned int num, t_flags *flags);

int	print_int_printf(int num, const char *ptr, char conversion)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character_printf(*(++ptr)))
		set_flags_printf(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	while ('0' <= *ptr && *ptr <= '9')
		ptr++;
	if (*ptr == '.')
	{
		flags.precision = ft_atoi(++ptr);
		flags.zero_padding = F_ZERO_PRECISION;
	}
	if (conversion == 'd' || conversion == 'i')
		return (print_dec_printf(num, &flags));
	if (conversion == 'x' || conversion == 'X')
		return (print_hex_printf(num, &flags, conversion));
	if (conversion == 'u')
		return (print_uint_printf((unsigned int)num, &flags));
	return (0);
}
