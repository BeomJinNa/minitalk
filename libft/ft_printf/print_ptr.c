/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:14:30 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:51:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "flags.h"

void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
void		set_flags_printf(const char c, t_flags *flags);
int			is_flag_character_printf(const char c);
static int	print_address(void *address, t_flags *flags);
size_t		digit_of_address_printf(unsigned long long num);
size_t		max_len_printf(size_t a, size_t b);
void		put_address_printf(unsigned long long num);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

int	print_ptr_printf(void *address, const char *ptr)
{
	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	while (is_flag_character_printf(*(++ptr)))
		set_flags_printf(*ptr, &flags);
	flags.width = ft_atoi(ptr);
	return (print_address(address, &flags));
}

static int	print_address(void *address, t_flags *flags)
{
	size_t	length;
	size_t	space;

	length = digit_of_address_printf((unsigned long long)address) + 2;
	space = max_len_printf(length, flags->width) - length;
	if (flags->left_align == 0)
		while (space-- > 0)
			ft_write_printf(" ", 1);
	ft_write_printf("0x", 2);
	put_address_printf((unsigned long long)address);
	if (flags->left_align == 1)
		while (space-- > 0)
			ft_write_printf(" ", 1);
	return (max_len_printf(length, flags->width));
}
