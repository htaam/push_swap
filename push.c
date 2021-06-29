/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:44 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/19 18:35:52 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	aux1(t_stack **src, t_stack **dst)
{
	if (*dst == NULL)
	{
		*src = (*src)->next;
		*dst = (*src)->prev;
		(*src)->prev = NULL;
		(*dst)->prev = NULL;
		(*dst)->next = NULL;
	}
	else
	{
		*src = (*src)->next;
		(*dst)->prev = (*src)->prev;
		(*dst)->prev->next = (*dst);
		(*dst) = (*dst)->prev;
		(*src)->prev = NULL;
		(*dst)->prev = NULL;
	}
}

void	aux2(t_stack **src, t_stack **dst)
{
	if (*dst == NULL)
	{
		*dst = *src;
		(*dst)->prev = NULL;
		(*dst)->next = NULL;
		*src = NULL;
	}
	else
	{
		(*dst)->prev = (*src);
		(*dst)->prev->next = (*dst);
		(*dst) = (*dst)->prev;
		(*src) = NULL;
		(*dst)->prev = NULL;
	}
}

void	aux(t_stack **src, t_stack **dst)
{
	if (*src)
		while ((*src)->prev)
			(*src) = (*src)->prev;
	if (*dst)
		while ((*dst)->prev)
			(*dst) = (*dst)->prev;
	if (*src && (stack_size(*src) > 1))
	{
		aux1(src, dst);
	}
	else if (*src)
	{
		aux2(src, dst);
	}
}

void	push_src_dst(t_holder *holder, char c)
{
	if (c == 'a')
	{
		if (!(holder)->stack_b)
			return ;
		aux(&holder->stack_b, &holder->stack_a);
	}
	if (c == 'b')
	{
		if (!(holder)->stack_a)
			return ;
		aux(&holder->stack_a, &holder->stack_b);
	}
}
