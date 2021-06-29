/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:35:49 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/22 18:03:53 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_pa (t_holder *holder)
{
	if (stack_size((holder)->stack_b) > 0)
		push_src_dst (holder, 'a');
	add_last_solution(&(holder)->solution, "pa\n");
}

void	push_pb (t_holder *holder)
{
	if (stack_size((holder)->stack_a) > 0)
		push_src_dst (holder, 'b');
	add_last_solution(&(holder)->solution, "pb\n");
}
