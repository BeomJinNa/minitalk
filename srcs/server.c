/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:04:20 by bena              #+#    #+#             */
/*   Updated: 2023/04/26 02:31:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

static void	get_signal(int sig);
static void	end_to_receive_the_message(pid_t client_pid);

int	main(void)
{
	const pid_t		my_pid = getpid();

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
	if (client_pid == -1 && digit == 65536)
	{
		digit = 1;
		client_pid = byte;
		byte = 0;
	}
	else if (client_pid >= 0 && digit == 256)
	{
		digit = 1;
		if (byte != 0)
			ft_putchar_fd((char)byte, 1);
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
	write(1, "\n", 1);
	kill(client_pid, SIGUSR1);
}
