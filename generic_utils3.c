/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:50 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/23 16:30:29 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*my_src;
	char	*my_dst;
	size_t	i;

	my_src = (char *)src;
	my_dst = (char *)dst;
	i = 0;
	if (!(my_src) && !(my_dst) && n > 0)
		return (dst);
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}

int	ft_strlen(char *str)
{
	int	counter;

	if (!*str)
		return (0);
	counter = 0;
	while (!(*str == 0))
	{
		counter++;
		str++;
	}
	return (counter);
}

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)c1;
	s2 = (char *)c2;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2++)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
		}
		if (*s1++ == 0)
			break ;
		n--;
	}
	return (0);
}

void	add_last(t_stack **stack, int a)
{
	t_stack		*temp;
	static int	first = 1;
	t_stack		*temp2;

	temp = *stack;
	if (first)
	{
		first = 0;
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = a;
		*stack = temp;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp2 = malloc(sizeof(t_stack));
		temp2->data = a;
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
	}
}
