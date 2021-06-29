/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_aux4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:27:29 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/19 18:28:18 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	find_pivot(t_stack *stack, int chunk_size)
{
	int	i;
	int	min;

	min = stack_min(stack);
	i = 0;
	while (i < chunk_size)
	{
		min = get_next_nbr(stack, min);
		if (min == stack_max(stack))
			break ;
		i++;
	}
	return (min);
}

int	is_any_in_stack(t_stack *stack, int pivot)
{
	int	i;

	i = 0;
	while (i < pivot)
	{
		if (is_x_in_stack(stack, i))
			return (1);
		i++;
	}
	return (0);
}

int	first_from_the_top(t_stack *stack, int pivot)
{
	while (stack)
	{
		if (stack->data < pivot)
			return (stack->data);
		if (stack->next)
			stack = stack->next;
	}
	return (0);
}

int	first_from_the_bot(t_stack *stack, int pivot)
{
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		if (stack->data < pivot)
			return (stack->data);
		if (stack->prev)
			stack = stack->prev;
	}
	return (0);
}

void	return_to_a(t_holder *holder)
{
	int	i;

	while (1)
	{
		if (stack_size(holder->stack_b) < 1)
			return ;
		i = stack_max(holder->stack_b);
		if (holder->stack_b->data == i)
			push_pa(holder);
		else
			move_x_to_top_of_B(holder, i);
	}
}
