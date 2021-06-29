/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_aux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:52:57 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/12 16:22:02 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	biggest_n_from_the_top(t_stack *stack, int n)
{
	int	to_return;

	to_return = INT_MIN;
	while (n)
	{
		if (stack->data > to_return)
			to_return = stack->data;
		if (stack->next)
			stack = stack->next;
		n--;
	}
	return (to_return);
}

static int	biggest_n_from_the_bot(t_stack *stack, int n)
{
	int	to_return;

	to_return = INT_MIN;
	while (stack->next)
		stack = stack->next;
	while (n)
	{
		if (stack->data > to_return)
			to_return = stack->data;
		if (stack->prev)
			stack = stack->prev;
		n--;
	}
	return (to_return);
}

int	biggest_whith_x_over2_moves(t_stack *stack, int x)
{
	int	max1;
	int	max2;
	int	n;

	n = x / 2;
	max1 = biggest_n_from_the_bot(stack, n);
	max2 = biggest_n_from_the_top(stack, n);
	if (max2 < max1)
		return (max1);
	return (max2);
}
