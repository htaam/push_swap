/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:33 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/15 15:52:46 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	count_bigger(t_stack *stack, int n)
{
	int	a;

	a = 0;
	while (stack)
	{
		if (stack->data > n)
			a++;
		stack = stack->next;
	}
	return (a);
}

static int	count_smaller(t_stack *stack, int n)
{
	int	a;

	a = 0;
	while (stack)
	{
		if (stack->data < n)
			a++;
		stack = stack->next;
	}
	return (a);
}

static int	get_avg(t_stack *stack)
{
	long long int	n;
	long long int	i;

	i = stack_size(stack);
	n = 0;
	while (stack)
	{
		n = n + stack->data;
		stack = stack->next;
	}
	return ((int)(n / i));
}

int	get_median(t_stack *stack)
{
	int				smaller;
	int				bigger;
	long long int	median_temp;

	median_temp = get_avg(stack);
	if (nbr_pos_stack(stack, median_temp) == -1)
		median_temp = get_previous_nbr(stack, median_temp);
	smaller = count_smaller(stack, median_temp);
	bigger = count_bigger(stack, median_temp);
	while (!(smaller >= bigger - 1 && smaller <= bigger + 1))
	{
		if (smaller > bigger)
			median_temp = get_previous_nbr (stack, median_temp);
		else
			median_temp = get_next_nbr (stack, median_temp);
		smaller = count_smaller(stack, median_temp);
		bigger = count_bigger(stack, median_temp);
	}
	return (median_temp);
}
