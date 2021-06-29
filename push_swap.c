/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:40:14 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/24 14:38:24 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	print_list_values(t_stack *stack)
{
	ft_putchar_fd('\n', 1);
	while (stack)
	{
		ft_putnbr_fd(stack->data, 1);
		ft_putchar_fd('\t', 1);
		stack = stack->next;
	}
}

void	sorting(t_holder *holder)
{
	int		a;
	int		b;

	a = stack_size((holder)->stack_a);
	b = stack_size((holder)->stack_b);
	if (a <= 5)
		small_sort(holder, a, b);
	else
		big_sort(holder);
	return ;
}

void	aux_holder(t_holder *holder)
{
	holder->solution->next = NULL;
	holder->solution->prev = NULL;
	holder->stack_a->next = NULL;
	holder->stack_a->prev = NULL;
}

int	main(int argc, char **argv)
{
	t_holder	*holder;
	int			i;
	int			a;

	holder = malloc (sizeof(t_holder));
	holder->stack_a = malloc (sizeof(t_stack));
	holder->solution = malloc (sizeof(t_solution));
	aux_holder(holder);
	i = 1;
	if (!is_duplicate(argv))
		ft_exit_error(holder);
	while (argv[i] && argc > 1)
	{
		a = ft_atoi_with_error(argv[i], holder);
		add_last(&holder->stack_a, a);
		i++;
	}
	if (!ft_stack_is_sorted(holder->stack_a))
		sorting(holder);
	print_solution_values(holder->solution);
	ft_clear_stack(&holder->stack_a);
	ft_clear_stack(&holder->stack_b);
	ft_clear_solution(&holder->solution);
	free(holder);
}
