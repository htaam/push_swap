/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:55 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/24 14:05:43 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static int	atoi_aux (char *ptr, long long int signal, t_holder *holder, int a)
{
	long long	result;

	result = 0;
	while ((ptr[a]))
	{
		if (!ft_isdigit(ptr[a]))
			ft_exit_error(holder);
		result = result * 10 + (ptr[a] - 48);
		a++;
	}
	if (signal * result < -2147483648 || signal * result > 2147483647)
		ft_exit_error(holder);
	return (result * signal);
}

long long int	ft_atoi_with_error(const char *str, t_holder *holder)
{
	long long int	signal;
	char			*ptr;
	int				a;

	a = 0;
	signal = 1;
	ptr = (char *)str;
	while ((ptr[a] == 32 || ptr[a] == '\t' || ptr[a] == '\v'
			|| ptr[a] == '\f' || ptr[a] == '\r' || ptr[a] == '\n') && ptr[a] != 0)
		a++;
	if (!(ptr[a]))
		ft_exit_error((holder));
	if (ptr[a] == '-' || ptr[a] == '+')
	{
		if (ptr[a] == '-')
			signal = -1;
		a++;
	}
	return (atoi_aux(ptr, signal, holder, a));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, &"-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, &"-", 1);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = n % 10 + '0';
		ft_putchar_fd(c, fd);
	}
}
