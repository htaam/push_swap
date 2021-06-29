/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_aux1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:52:57 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/12 16:21:56 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	smallest_n_from_the_top(t_stack *stack, int n)
{
	int	to_return;

	to_return = INT_MAX;
	while (n)
	{
		if (stack->data < to_return)
			to_return = stack->data;
		if (stack->next)
			stack = stack->next;
		n--;
	}
	return (to_return);
}

static int	smallest_n_from_the_bot(t_stack *stack, int n)
{
	int	to_return;

	to_return = INT_MAX;
	while (stack->next)
		stack = stack->next;
	while (n)
	{
		if (stack->data < to_return)
			to_return = stack->data;
		if (stack->prev)
			stack = stack->prev;
		n--;
	}
	return (to_return);
}

int	smallest_whith_x_over2_moves(t_stack *stack, int x)
{
	int	min1;
	int	min2;
	int	n;

	n = x / 2;
	min1 = smallest_n_from_the_bot(stack, n);
	min2 = smallest_n_from_the_top(stack, n);
	if (min2 < min1)
		return (min2);
	return (min1);
}
