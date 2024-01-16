/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:01:14 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/16 17:34:16 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_num **a, t_num **b)
{
	int	count;

	count = count_stack(*a);
	if (count == 1)
		return ;
	else if (count < 4)
		sort_ascending(a);
	else if (count < 7)
		sort_b(a, b);
	else
		quick_sort(a, b);
}

void	sort_ascending(t_num **stack)
{
	int	i;
	t_num	*top;
	t_num	*bottom;

	i = 0;
	top = *stack;
	bottom = bottom_stack(top);
	if (count_stack(*stack) == 1)
		return ;
	while (i < 3)
	{
		if (top->rank > top->next->rank)
			swap_a(stack);
		else if (top->rank > bottom->rank)
			reverse_rotate_a(stack);
		else if (top->next->rank > bottom->rank)
			reverse_rotate_a(stack);
		top = *stack;
		bottom = bottom_stack(top);
		i++;
	}
}

void	sort_descending(t_num **stack)
{
	int	i;
	t_num	*top;
	t_num	*bottom;

	i = 0;
	top = *stack;
	bottom = bottom_stack(top);
	if (count_stack(*stack) == 1)
		return ;
	while (i < 3)
	{
		if (top->rank < top->next->rank)
			swap_a(stack);
		else if (top->rank < bottom->rank)
			reverse_rotate_a(stack);
		else if (top->next->rank < bottom->rank)
			reverse_rotate_a(stack);
		top = *stack;
		bottom = bottom_stack(top);
		i++;
	}
}

int	same_rank_check(t_num *stack, int num)
{
	t_num	*curr;

	curr = stack;
	while (curr != NULL)
	{
		if (curr->rank == num)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	sort_b(t_num **a, t_num **b)
{
	int	mini_rank;

	mini_rank = 1;
	while (count_stack(*a) > 3)
	{
		if ((*a)->rank == mini_rank)
		{
			push_b(b, a);
			if (same_rank_check(*a, mini_rank) == 0)
				mini_rank++;
		}
		else
			rotate_a(a);
	}
	sort_ascending(a);
	while (count_stack(*b) > 0)
	{
		ft_printf("a\n");
		print_stack(*a);
		ft_printf("b\n");
		print_stack(*b);
		push_a(a, b);
	}
}

int	less_than_pivot_check(t_num *stack, int pivot)
{
	t_num	*curr;

	curr = stack;
	while (curr != NULL)
	{
		if (curr->rank <= pivot)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	greater_than_pivot_check(t_num *stack, int pivot)
{
	t_num	*curr;

	curr = stack;
	while (curr != NULL)
	{
		if (curr->rank > pivot)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	decide_pivot(t_num *stack)
{
	t_num	*curr;
	int	sum;
	int	i;

	curr = stack;
	sum = 0;
	i = 0;
	while (i < 3 && curr != NULL)
	{
		sum += curr->rank;
		i++;
		curr = curr->next;
	}
	return (sum / i);
}

int	is_limit(t_num *stack)
{
	int	i;
	t_num	*curr;

	i = 0;
	curr = stack;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i < 3);
}

void	quick_sort(t_num **a, t_num **b)
{
	int	pivot;

	//仮に2個目のrankをpivotにする
	pivot = decide_pivot(*a);
	while (less_than_pivot_check(*a, pivot))
	{
		rotate_a(a);
		if ((*a)->rank <= pivot)
			push_b(b, a);
	}
	ft_printf("pivot\t%d\n", pivot);
	ft_printf("a\n");
	print_stack(*a);
	ft_printf("b\n");
	print_stack(*b);
	pivot = decide_pivot(*b);
	while (greater_than_pivot_check(*b, pivot))
	{
		rotate_a(b);
		if ((*b)->rank > pivot)
			push_a(a, b);
	}
	ft_printf("pivot\t%d\n", pivot);
	ft_printf("a\n");
	print_stack(*a);
	ft_printf("b\n");
	print_stack(*b);
	pivot = decide_pivot(*b);
	while (greater_than_pivot_check(*b, pivot))
	{
		rotate_a(b);
		if ((*b)->rank > pivot)
			push_a(a, b);
	}
	ft_printf("pivot\t%d\n", pivot);
	ft_printf("a\n");
	print_stack(*a);
	ft_printf("b\n");
	print_stack(*b);
	push_a(a, b);
	rotate_a(a);
	push_a(a, b);
	rotate_a(a);
	ft_printf("a\n");
	print_stack(*a);
	ft_printf("b\n");
	print_stack(*b);
}

