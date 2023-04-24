/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:17:32 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:18:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	output;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	output = 0;
	while ('0' <= *str && *str <= '9')
	{
		output = output * 10 + *str - '0';
		str++;
	}
	return (sign * output);
}
