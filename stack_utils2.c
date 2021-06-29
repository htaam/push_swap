/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:26 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/17 17:52:29 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	stack_size (t_stack *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = 0;
	while ((stack))
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	stack_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	nbr_pos_stack(t_stack *stack, int a)
{
	int	n;

	n = 0;
	while (stack)
	{
		if (stack->data == a)
			return (n);
		n++;
		stack = stack->next;
	}
	return (-1);
}

int	get_value_pos(t_stack *stack, int n)
{
	int	a;

	while (n--)
		stack = stack->next;
	a = stack->data;
	return (a);
}
