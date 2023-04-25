/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/02/27 18:50:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static int	flush_buffer(char *buffer, char **ptr_buf);
static int	print_conversion(const char **ptr, va_list *ap);
int			print_int_printf(int num, const char *ptr, char conversion);
int			print_uint_printf(unsigned int num, const char *ptr);
int			print_char_printf(char c, const char *ptr);
int			print_str_printf(char *str, const char *ptr);
int			print_ptr_printf(void *address, const char *ptr);
int			is_passable_character_printf(const char c);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		buffer[4096];
	const char	*ptr;
	char		*ptr_buf;
	int			output;

	va_start(ap, format);
	ptr_buf = buffer;
	ptr = format;
	output = 0;
	while (ptr != NULL && *ptr)
	{
		if (*ptr == '\n' || *ptr == '%' || ptr_buf - buffer == 4096)
			output += flush_buffer(buffer, &ptr_buf);
		if (*ptr == '%')
			output += print_conversion(&ptr, &ap);
		if (ptr != NULL && *ptr && *ptr != '%')
			*ptr_buf++ = *ptr++;
	}
	va_end(ap);
	output += flush_buffer(buffer, &ptr_buf);
	if (ptr == NULL || ft_write_printf(NULL, 0) == -1)
		return (-1);
	return (output);
}

static int	flush_buffer(char *buffer, char **ptr_buf)
{
	int	output;

	if (buffer >= *ptr_buf)
		return (0);
	ft_write_printf(buffer, *ptr_buf - buffer);
	output = *ptr_buf - buffer;
	*ptr_buf = buffer;
	return (output);
}

static int	print_conversion(const char **ptr, va_list *ap)
{
	const char	*c;
	int			conversion_length;

	c = *ptr;
	while (is_passable_character_printf(*(++c)))
		;
	if (*c == 'i' || *c == 'd' || *c == 'x' || *c == 'X' || *c == 'u')
		conversion_length = print_int_printf(va_arg(*ap, int), *ptr, *c);
	if (*c == 'c')
		conversion_length = print_char_printf(va_arg(*ap, int), *ptr);
	if (*c == 's')
		conversion_length = print_str_printf(va_arg(*ap, char *), *ptr);
	if (*c == 'p')
		conversion_length = print_ptr_printf(va_arg(*ap, void *), *ptr);
	if (*c == '%')
		conversion_length = print_char_printf('%', *ptr);
	if (*c == '\0')
	{
		*ptr = NULL;
		return (0);
	}
	*ptr = c + 1;
	return (conversion_length);
}
