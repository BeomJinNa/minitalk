/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:04:20 by bena              #+#    #+#             */
/*   Updated: 2023/04/26 04:22:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

static void	send_one_byte(pid_t pid, int byte);
static void	send_my_pid(pid_t target_pid);
static void	print_signal(int sig);

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*ptr;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, print_signal);
	send_my_pid(pid);
	ptr = av[2];
	while (*ptr)
	{
		send_one_byte(pid, *ptr);
		ptr++;
	}
	send_one_byte(pid, '\0');
	usleep(1000);
	return (0);
}

static void	send_one_byte(pid_t pid, int byte)
{
	int	digit;

	digit = 1;
	while (digit < 256)
	{
		if (byte & digit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit <<= 1;
		usleep(40);
	}
}

static void	send_my_pid(pid_t target_pid)
{
	const pid_t	my_pid = getpid();

	send_one_byte(target_pid, my_pid % 256);
	send_one_byte(target_pid, (my_pid % 65536) / 256);
	send_one_byte(target_pid, my_pid / 65536);
}

static void	print_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("server feedback : sending successful\n");
}
