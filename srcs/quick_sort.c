/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:57:51 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/30 01:40:26 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_num **a, t_num **b)
{
	int		pivot_a;
	int		sorted_pivot;
	t_pivot	*pivot;
	t_pivot	*pivot_stack;

	sorted_pivot = 0;
	while (is_sorted(*a) == 0)
	{
		pivot_stack = NULL;
		pivot_a = decide_pivot(*a, sorted_pivot);
		move_a2b(a, b, pivot_a, sorted_pivot);
		if (sorted_pivot != 0)
		{
			while ((*a)->prev->rank != sorted_pivot)
				reverse_rotate_a(a);
		}
		sorted_pivot = pivot_a;
		pivot = new_pivot(sorted_pivot);
		if (pivot == NULL)
			exit_on_error(*a, *b, pivot_stack);
		push_pivot_stack(&pivot_stack, pivot);
		while (pivot_stack != NULL)
			devide_stack(a, b, &pivot_stack);
	}
}

//median of stack
int	decide_pivot(t_num *stack, int min)
{
	return (min + (count_stack_greater_than_pivot(stack, min) / 2));
}

void	quick_sort_util(t_num **a, t_num **b)
{
	sort_b_ascending(b);
	while (count_stack(*b) > 0)
	{
		push_a(a, b);
		rotate_a(a);
	}
}

int	count_stack_greater_than_pivot(t_num *stack, int min)
{
	int		count;
	t_num	*curr;

	count = 0;
	if (stack == NULL)
		return (0);
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->prev->rank >= min)
			count++;
		curr = curr->next;
	}
	if (curr->prev->rank >= min)
		count++;
	return (count);
}

void	devide_stack(t_num **a, t_num **b, t_pivot **pivot_stack)
{
	int		pivot_b;
	int		count_b;
	t_pivot	*old;
	t_pivot	*new;

	count_b = count_stack(*b);
	if (count_b == 0)
	{
		if ((*pivot_stack)->next != NULL)
			move_a2b(a, b, (*pivot_stack)->next->pivot, (*pivot_stack)->pivot);
		old = pop_pivot_stack(pivot_stack);
		free(old);
	}
	else if (count_b < 4)
		quick_sort_util(a, b);
	else
	{
		pivot_b = decide_pivot(*b, stack_rank_min(*b));
		new = new_pivot(pivot_b);
		if (new == NULL)
			exit_on_error(*a, *b, *pivot_stack);
		push_pivot_stack(pivot_stack, new);
		move_b2a(a, b, pivot_b);
	}
}
