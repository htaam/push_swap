/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:52 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/09 17:52:08 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_exit_error(t_holder *holder)
{
	ft_clear_stack(&(*holder).stack_a);
	ft_clear_stack(&(*holder).stack_b);
	ft_putchar_fd('E', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*rt;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	rt = malloc(sizeof(char) * (len + 1));
	if (!(rt))
		return (NULL);
	ft_memcpy(rt, s1, ft_strlen(s1));
	ft_memcpy(rt + ft_strlen(s1), s2, ft_strlen(s2));
	rt[len] = 0;
	temp = rt;
	free(rt);
	return (temp);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (str)
		ft_memcpy(str, s1, size);
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (s)
	{
		while (s[a])
			write(fd, &s[a++], 1);
	}
}
