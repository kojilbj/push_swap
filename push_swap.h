/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:17:19 by kojwatan          #+#    #+#             */
/*   Updated: 2024/02/27 17:14:09 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_num
{
	int				content;
	int				rank;
	struct s_num	*prev;
	struct s_num	*next;
}	t_num;

typedef struct s_pivot
{
	int				pivot;
	struct s_pivot	*next;
}	t_pivot;

//terminate.c
void	exit_on_error(t_num *a, t_num *b, t_pivot *pivot_stack);
void	free_stack(t_num *stack);
void	free_pivot_stack(t_pivot *stack);

//stack_utils.c
int		stack_max(t_num *stack);
int		stack_rank_max(t_num *stack);
int		stack_rank_min(t_num *stack);
int		count_stack(t_num *stack);
int		count_stack_greater_than_pivot(t_num *stack, int min);

//stack_init.c
void	stack_init_util(t_num **stack, char *av);
void	stack_init(t_num **stack, char **av);

//corrdinate_compression.c
int		search_min(t_num *stack);
void	assign_rank(t_num *stack, int min, int i);
void	coordinate_compression(t_num *stack);

//control_stack.c
t_num	*bottom_stack(t_num *stack);
t_num	*num_new(int conent);
void	push_stack(t_num **stack, t_num *new);
t_num	*pop_stack(t_num **stack);

//swap.c
void	swap(t_num **stack);
void	swap_a(t_num **a);
void	swap_b(t_num **b);
void	swap_ab(t_num **a, t_num **b);

//push.c
void	push_a(t_num **a, t_num **b);
void	push_b(t_num **b, t_num **a);

//rotate.c
void	rotate(t_num **stack);
void	rotate_a(t_num **a);
void	rotate_b(t_num **b);
void	rotate_ab(t_num **a, t_num **b);

//reverse_rotate.c
void	reverse_rotate(t_num **stack);
void	reverse_rotate_a(t_num **a);
void	reverse_rotate_b(t_num **b);
void	reverse_rotate_ab(t_num **a, t_num **b);

//sort.c
int		decide_pivot(t_num *stack, int min);
void	sort(t_num **a, t_num **b);
void	sort_426(t_num **a, t_num **b);

//check.c
int		less_than_pivot_check(t_num *stack, int pivod, int last_pivot);
int		greater_than_pivot_check(t_num *stack, int pivot);
int		is_sorted(t_num *stack);

//move_stack2stack.c
void	move_a2b(t_num **a, t_num **b, int pivot_a, int sorted_pivot);
void	move_b2a(t_num **a, t_num **b, int pivot_b);

//cotrol_a.c
void	sort_a_ascending_util(t_num **stack);
void	sort_a_ascending(t_num **stack);

//cotrol_b.c
void	sort_b_ascending_util(t_num **stack);
void	sort_b_ascending(t_num **stack);

//stack_pivot.c
t_pivot	*new_pivot(int pivot);
void	push_pivot_stack(t_pivot **stack, t_pivot *new);
t_pivot	*pop_pivot_stack(t_pivot **stack);

//quick_sort.c
void	quick_sort(t_num **a, t_num **b);
int		decide_pivot(t_num *stack, int min);
void	quick_sort_util(t_num **a, t_num **b);
int		count_stack_greater_than_pivot(t_num *stack, int min);
void	devide_stack(t_num **a, t_num **b, t_pivot **pivot_stack);

//validates.c
int		validate_char(char c);
int		validate_duplicate(t_num *stack);
int		empty_check(char *str);
int		validate(char **av);

//validate_atoi.c
int		validate_atoi(const char *str);

#endif
