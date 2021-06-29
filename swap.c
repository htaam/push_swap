/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:21 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/22 18:03:37 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap_sa(t_holder *holder)
{
	if (stack_size((holder)->stack_a) > 1)
		swap_values(&(holder)->stack_a);
	add_last_solution(&(holder)->solution, "sa\n");
}

void	swap_sb(t_holder *holder)
{
	if (stack_size((holder)->stack_b) > 1)
		swap_values(&(holder)->stack_b);
	add_last_solution(&(holder)->solution, "sb\n");
}

void	swap_values(t_stack **src_stack)
{
	int		temp1;
	int		temp2;
	t_stack	*stack;

	stack = *src_stack;
	while (stack->prev)
		stack = stack->prev;
	temp1 = stack->data;
	stack = stack->next;
	temp2 = stack->data;
	stack->data = temp1;
	stack = stack->prev;
	stack->data = temp2;
	while (stack->prev)
		stack = stack->prev;
	*src_stack = stack;
}
