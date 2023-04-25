/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:04:20 by bena              #+#    #+#             */
/*   Updated: 2023/04/26 05:15:11 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft_bonus.h"

static void	get_signal(int sig);
static void	end_to_receive_the_message(pid_t client_pid);
static void	print_bytes(char c);

int	main(void)
{
	const pid_t	my_pid = getpid();

	ft_printf("pid : %d\n", my_pid);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	return (0);
}

static void	get_signal(int sig)
{
	static pid_t	client_pid = -1;
	static int		byte;
	static int		digit = 1;

	if (sig == SIGUSR1)
		byte |= digit;
	digit <<= 1;
	if (client_pid == -1 && digit == 16777216)
	{
		digit = 1;
		client_pid = byte;
		byte = 0;
	}
	else if (client_pid >= 0 && digit == 256)
	{
		digit = 1;
		if (byte != 0)
			print_bytes((char)byte);
		else
		{
			end_to_receive_the_message(client_pid);
			client_pid = -1;
		}
		byte = 0;
	}
}

static void	end_to_receive_the_message(pid_t client_pid)
{
	print_bytes('\0');
	write(1, "\n", 1);
	kill(client_pid, SIGUSR1);
}

static void	print_bytes(char c)
{
	static char	buffer[32];
	static char	*ptr = buffer;

	if (c != '\0' && ptr - buffer < 30)
		*ptr++ = c;
	else
	{
		if (buffer == ptr)
			return ;
		*ptr++ = c;
		*ptr = '\0';
		ft_printf("%s", buffer);
		ptr = buffer;
		ft_memset(buffer, 0, 32);
	}
}
