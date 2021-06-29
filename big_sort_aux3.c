/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_aux3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:01:57 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/19 19:16:49 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	number_closest_to_the_top(t_stack *stack, int pivot)
{
	int	top;
	int	bot;
	int	to_return;

	top = first_from_the_top(stack, pivot);
	bot = first_from_the_bot(stack, pivot);
	if (nbr_pos_stack(stack, top)
		<= (stack_size(stack) - nbr_pos_stack(stack, bot)))
		to_return = top;
	else
		to_return = bot;
	return (to_return);
}

void	rotate_and_PB_i(t_holder *holder, int i)
{
	while (1)
	{
		if ((holder->stack_a->data) == i)
		{
			sorted_PB(holder);
			return ;
		}
		move_x_to_top_of_A(holder, i);
	}
}

void	move_x_to_top_of_A(t_holder *holder, int i)
{
	if (nbr_pos_stack(holder->stack_a, i)
		<= (stack_size(holder->stack_a) / 2)
		&& nbr_pos_stack(holder->stack_a,
			i) != 0)
		rotate_ra(holder);
	else if (nbr_pos_stack(holder->stack_a, i)
		> (stack_size(holder->stack_a) / 2))
		rev_rotate_ra(holder);
}

void	move_x_to_top_of_B(t_holder *holder, int x)
{
	while (holder->stack_b->data != x)
	{
		if (nbr_pos_stack(holder->stack_b, x)
			<= (stack_size(holder->stack_b) / 2)
			&& nbr_pos_stack(holder->stack_b,
				x) != 0)
			rotate_rb(holder);
		else if (nbr_pos_stack(holder->stack_b, x)
			> (stack_size(holder->stack_b) / 2))
			rev_rotate_rb(holder);
	}
}

void	sorted_PB(t_holder *holder)
{
	if (stack_size(holder->stack_b) == 0)
		push_pb(holder);
	else if (holder->stack_a->data > get_previous_nbr(holder->stack_b,
			holder->stack_a->data))
	{	
		while (1)
		{
			if (holder->stack_b->data == get_previous_nbr(holder->stack_b,
					holder->stack_a->data))
			{
				push_pb(holder);
				break ;
			}
			move_x_to_top_of_B(holder, get_previous_nbr(holder->stack_b,
					holder->stack_a->data));
		}
	}
	else if (holder->stack_a->data < stack_min(holder->stack_b))
	{
		move_x_to_top_of_B(holder, stack_min(holder->stack_b));
		push_pb(holder);
		swap_sb(holder);
	}
	else
		push_pb(holder);
}
