/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:29 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/24 13:53:22 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*temp;

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

int	is_duplicate(char **argv)
{
	int	a;
	int	b;

	a = 1;
	while (argv[a])
	{
		b = 1;
		while (argv[b])
		{
			if (a != b && ft_strncmp(argv[a], argv[b], 100) == 0)
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	add_first(t_stack **stack, int a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	while ((*stack)->prev)
		(*stack) = (*stack)->prev;
	temp2 = *stack;
	temp1 = malloc(sizeof(t_stack));
	if (!temp1)
		return ;
	temp1->data = a;
	temp2 = *stack;
	*stack = temp1;
	temp1->next = temp2;
	temp1->prev = NULL;
}

void	delete_node(t_stack **src_stack)
{	
	t_stack	*temp;

	while ((*src_stack)->prev)
		(*src_stack) = (*src_stack)->prev;
	if (*src_stack)
	{
		temp = *src_stack;
		if ((*src_stack)->next)
			(*src_stack)->next->prev = temp->prev;
		if ((*src_stack)->prev)
			(*src_stack)->prev->next = (*src_stack)->next;
		if ((*src_stack)->prev)
			*src_stack = (*src_stack)->prev;
		else
			*src_stack = (*src_stack)->next;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
