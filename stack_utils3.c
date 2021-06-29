/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:55:17 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/22 17:58:18 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	get_previous_nbr(t_stack *stack, int n)
{
	int	a;

	a = INT_MIN;
	while (stack)
	{
		if (stack->data > a && stack->data < n)
			a = stack->data;
		stack = stack->next;
	}
	if (a == INT_MIN)
		a = n;
	return (a);
}

int	get_next_nbr(t_stack *stack, int n)
{
	int	a;

	a = INT_MAX;
	while (stack)
	{
		if (stack->data < a && stack->data > n)
			a = stack->data;
		stack = stack->next;
	}
	if (a == INT_MAX)
		a = n;
	return (a);
}

int	is_x_in_stack(t_stack *stack, int x)
{
	while (stack)
	{
		if (stack->data == x)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	get_value_pos_from_bot(t_stack *stack, int n)
{
	int	a;

	while (n--)
		stack = stack->next;
	a = stack->data;
	return (a);
}

int	ft_stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
