/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:41 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/22 18:00:36 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rev_rotate_ra (t_holder *holder)
{
	if (stack_size((holder)->stack_a) > 1)
		rev_rotate_values (&holder->stack_a);
	add_last_solution(&(holder)->solution, "rra\n");
}

void	rev_rotate_rb (t_holder *holder)
{
	if (stack_size((holder)->stack_b) > 1)
		rev_rotate_values (&(holder)->stack_b);
	add_last_solution(&(holder)->solution, "rrb\n");
}

void	rev_rotate_values(t_stack **src_stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;
	t_stack	*stack;

	stack = *src_stack;
	while (stack->prev)
		stack = stack->prev;
	temp1 = stack;
	while (stack->next)
		stack = stack->next;
	temp3 = stack;
	temp2 = stack->prev;
	temp1->prev = temp3;
	temp3->prev = NULL;
	temp3->next = temp1;
	temp2->next = NULL;
	while (stack->prev)
		stack = stack->prev;
	*src_stack = stack;
}
