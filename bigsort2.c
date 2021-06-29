/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:42:27 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/23 16:11:15 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	cpy_sol(t_solution *stack, t_solution **cpy)
{
	while (stack)
	{
		(*cpy)->instruction = stack->instruction;
		if (stack->next)
			(stack) = stack->next;
		else
			break ;
		if ((*cpy)->next)
			(*cpy) = (*cpy)->next;
		else
			break ;
	}
}

void	cpy_stack(t_stack *stack, t_stack **cpy)
{
	while (stack)
	{
		(*cpy)->data = stack->data;
		if (stack->next)
			(stack) = stack->next;
		else
			break ;
		if ((*cpy)->next)
			(*cpy) = (*cpy)->next;
		else
			break ;
	}
}

void	big_sort(t_holder	*holder)
{
	int	n;

	if (stack_size(holder->stack_a) < 200)
		n = 5;
	else
		n = 11;
	big_sort2(holder, n);
}

void	big_sort2(t_holder *holder, int n)
{
	int	chunck_size;
	int	i;
	int	pivot;
	int	aa;

	aa = 0;
	chunck_size = stack_size(holder->stack_a) / n;
	while (!ft_stack_is_sorted(holder->stack_a))
	{
		pivot = find_pivot(holder->stack_a, chunck_size);
		while (is_any_in_stack(holder->stack_a, pivot) != 0)
		{
			i = number_closest_to_the_top(holder->stack_a, pivot);
			while (is_x_in_stack(holder->stack_a, i))
			{
				rotate_and_PB_i(holder, i);
			}
		}
	}
	return_to_a(holder);
}
