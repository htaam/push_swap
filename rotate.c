/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:39 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/22 18:00:27 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rotate_ra (t_holder *holder)
{
	if (stack_size((holder)->stack_a) > 1)
		rotate_values (&(holder)->stack_a);
	add_last_solution(&(holder)->solution, "ra\n");
}

void	rotate_rb (t_holder *holder)
{
	if (stack_size((holder)->stack_b) > 1)
		rotate_values (&(holder)->stack_b);
	add_last_solution(&(holder)->solution, "rb\n");
}

void	rotate_values(t_stack **src_stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;
	t_stack	*stack;

	stack = *src_stack;
	temp1 = stack;
	temp2 = stack->next;
	while (stack->next)
		stack = stack->next;
	temp3 = stack;
	temp1->prev = temp3;
	temp1->next = NULL;
	temp2->prev = NULL;
	temp3->next = temp1;
	while (stack->prev)
		stack = stack->prev;
	*src_stack = stack;
}
