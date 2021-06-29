/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:36 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/12 15:29:16 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	sort_3(t_holder *holder)
{
	if (nbr_pos_stack((holder)->stack_a, stack_max((holder)->stack_a)) == 0)
	{
		if (nbr_pos_stack((holder)->stack_a, stack_min((holder)->stack_a)) == 1)
			rotate_ra(holder);
		else
		{
			swap_sa(holder);
			rev_rotate_ra(holder);
		}
	}
	else if (nbr_pos_stack((holder)->stack_a,
			stack_max((holder)->stack_a)) == 1)
	{
		if (nbr_pos_stack((holder)->stack_a, stack_min((holder)->stack_a)) == 0)
		{
			swap_sa(holder);
			rotate_ra(holder);
		}
		else
			rev_rotate_ra(holder);
	}
	else
		swap_sa(holder);
}

static void	aux_to_5(t_holder *holder, int smallest)
{
	int	second_smallest;

	second_smallest = get_next_nbr(holder->stack_a, smallest);
	while (stack_size((holder)->stack_b) < 2)
	{
		if (holder->stack_a->data == smallest || holder->stack_a->data
			== second_smallest)
		{
			push_pb(holder);
		}
		if (nbr_pos_stack(holder->stack_a, stack_min(holder->stack_a))
			<= (stack_size(holder->stack_a) / 2)
			&& nbr_pos_stack(holder->stack_a,
				stack_min(holder->stack_a)) != 0)
			rotate_ra(holder);
		else if (nbr_pos_stack(holder->stack_a, stack_min(holder->stack_a))
			> (stack_size(holder->stack_a) / 2))
			rev_rotate_ra(holder);
	}
}

static void	sort_to_5(t_holder *holder)
{
	int	smallest;

	smallest = stack_min(holder->stack_a);
	aux_to_5(holder, smallest);
	if (!ft_stack_is_sorted((holder)->stack_a)
		&& stack_size(holder->stack_a) == 3)
		sort_3(holder);
	else if (!ft_stack_is_sorted((holder)->stack_a)
		&& (stack_size(holder->stack_a) != 3))
		swap_sa(holder);
	if (holder->stack_b->data == smallest)
		rotate_rb(holder);
	push_pa(holder);
	push_pa(holder);
}

void	small_sort(t_holder *holder, int a, int b)
{
	if ((holder)->stack_b)
		b = b + 1;
	while (a == 2 && !ft_stack_is_sorted((holder)->stack_a))
	{
		swap_sa(holder);
		if (ft_stack_is_sorted((holder)->stack_a))
			return ;
	}
	while (a < 4 && !ft_stack_is_sorted((holder)->stack_a))
	{
		sort_3(holder);
		if (ft_stack_is_sorted((holder)->stack_a))
			return ;
	}
	while ((a < 6 && !ft_stack_is_sorted((holder)->stack_a))
		|| stack_size((holder)->stack_b) != 0)
	{
		sort_to_5(holder);
	}
	return ;
}
