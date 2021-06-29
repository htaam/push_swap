/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:33:51 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/23 16:05:10 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	add_last_solution(t_solution **stack, char *a)
{
	t_solution		*temp;
	t_solution		*temp2;

	temp = *stack;
	if (!temp->instruction)
	{
		temp->next = NULL;
		temp->prev = NULL;
		temp->instruction = a;
		*stack = temp;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp2 = malloc(sizeof(t_solution));
		temp2->instruction = a;
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
	}
	while (temp->prev)
		temp = temp->prev;
	*stack = temp;
}

void	print_solution_values(t_solution *solution)
{
	while (solution)
	{
		ft_putstr_fd(solution->instruction, 1);
		solution = solution->next;
	}
}

void	ft_clear_solution(t_solution **stack)
{
	t_solution	*temp;

	temp = *stack;
	while (temp)
	{
		(*stack) = temp;
		temp = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		free (*stack);
	}
}

int	solution_size (t_solution *stack)
{
	int	n;

	if (!stack)
		return (0);
	n = 0;
	while ((stack))
	{
		n++;
		stack = stack->next;
	}
	return (n);
}
