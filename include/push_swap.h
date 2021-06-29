/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:24:58 by tmatias           #+#    #+#             */
/*   Updated: 2021/06/24 13:52:34 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_solution
{
	char				*instruction;
	struct s_solution	*next;
	struct s_solution	*prev;
}						t_solution;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_holder
{
	t_solution		*solution;
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_holder;

int				count_instructions(t_holder *holder);
int				ft_stack_is_sorted(t_stack *stack);
void			rev_rotate_values(t_stack **src_stack);
void			ft_clear_stack(t_stack **stack);
int				ft_strncmp(const char *c1, const char *c2, size_t n);
int				is_duplicate(char **argv);
void			add_first(t_stack **stack, int a);
void			delete_node(t_stack **src_stack);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_exit_error(t_holder *holder);
int				ft_isdigit(int c);
long long int	ft_atoi_with_error(const char *str, t_holder *holder);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			swap_values(t_stack **src_stack);
void			rotate_values(t_stack **src_stack);
int				stack_size (t_stack *stack);
int				stack_max(t_stack *stack);
int				stack_min(t_stack *stack);
int				is_x_in_stack(t_stack *stack, int x);
void			small_sort(t_holder *holder, int a, int b);
void			swap_sa(t_holder *holder);
void			swap_sb(t_holder *holder);
void			swap_ss(t_holder *holder);
int				nbr_pos_stack(t_stack *stack, int a);
void			rotate_ra (t_holder *holder);	
void			rotate_rb (t_holder *holder);
void			rotate_rr (t_holder *holder);
void			rev_rotate_ra (t_holder *holder);
void			rev_rotate_rb (t_holder *holder);
void			rev_rotate_rr (t_holder *holder);
int				get_median(t_stack *stack);
void			print_list_values(t_stack *stack);
int				get_value_pos(t_stack *stack, int n);
void			push_pb (t_holder *holder);
void			push_pa (t_holder *holder);
void			push_src_dst(t_holder *holder, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);
int				get_previous_nbr(t_stack *stack, int n);
int				get_next_nbr(t_stack *stack, int n);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			print_list_values(t_stack *stack);
char			*ft_strdup(char *s1);

void			big_sort2(t_holder *holder, int n);
int				number_closest_to_the_top(t_stack *stack, int pivot);
int				is_any_in_stack(t_stack *stack, int pivot);
int				find_pivot(t_stack *stack, int chunk_size);
void			rotate_and_PB_i(t_holder *holder, int i);
void			return_to_a(t_holder *holder);
void			sorted_PB(t_holder *holder);
void			move_x_to_top_of_B(t_holder *holder, int x);
void			move_x_to_top_of_A(t_holder *holder, int i);
void			big_sort(t_holder *holder);
int				biggest_whith_x_over2_moves(t_stack *stack, int x);
int				smallest_whith_x_over2_moves(t_stack *stack, int x);
int				first_from_the_top(t_stack *stack, int pivot);
int				first_from_the_bot(t_stack *stack, int pivot);

void			add_last_solution(t_solution **stack, char *a);
void			print_solution_values(t_solution *solution);
int				solution_size (t_solution *stack);
void			ft_clear_solution(t_solution **stack);

void			add_last(t_stack **stack, int a);

void			add_doubles(t_solution **solution);	

#endif