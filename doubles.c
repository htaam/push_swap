/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:03:27 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/23 16:12:43 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "include/push_swap.h"

void	double_rr(t_solution **solution)
{
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
	while ((*solution))
	{
		if (!ft_strncmp((*solution)->instruction, "ra\n", 5))
		{
			if (!ft_strncmp((*solution)->next->instruction, "rb\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("rr\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if (!ft_strncmp((*solution)->instruction, "rb\n", 4))
		{
			if (!ft_strncmp((*solution)->next->instruction, "ra\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("rr\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if ((*solution)->next)
			(*solution) = (*solution)->next;
		else
			break ;
	}
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
}

void	double_rrr(t_solution **solution)
{
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
	while ((*solution))
	{
		if (!ft_strncmp((*solution)->instruction, "rra\n", 5))
		{
			if (!ft_strncmp((*solution)->next->instruction, "rrb\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("rrr\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if (!ft_strncmp((*solution)->instruction, "rrb\n", 4))
		{
			if (!ft_strncmp((*solution)->next->instruction, "rra\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("rrr\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if ((*solution)->next)
			(*solution) = (*solution)->next;
		else
			break ;
	}
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
}

void	double_ss(t_solution **solution)
{
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
	while ((*solution))
	{
		if (!ft_strncmp((*solution)->instruction, "sa\n", 5))
		{
			if (!ft_strncmp((*solution)->next->instruction, "sb\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("ss\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if (!ft_strncmp((*solution)->instruction, "sb\n", 4))
		{
			if (!ft_strncmp((*solution)->next->instruction, "sa\n", 5))
			{
				free((*solution)->instruction);
				(*solution)->instruction = ft_strdup("ss\n");
				(*solution)->next = (*solution)->next->next;
				(*solution)->next->prev = (*solution);
			}
		}
		if ((*solution)->next)
			(*solution) = (*solution)->next;
		else
			break ;
	}
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
}

void	add_doubles(t_solution **solution)
{
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
	double_rr(solution);
	double_rrr(solution);
	double_ss(solution);
	while ((*solution)->prev)
		(*solution) = (*solution)->prev;
}*/
