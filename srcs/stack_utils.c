/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:08:15 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 15:43:57 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_max(t_num *stack)
{
	int		max;
	t_num	*curr;

	if (stack == NULL)
		return (0);
	max = stack->content;
	curr = stack->next;
	while (curr != stack)
	{
		if (max < curr->content)
			max = curr->content;
		curr = curr->next;
	}
	if (max < curr->content)
		max = curr->content;
	return (max);
}

int	stack_rank_max(t_num *stack)
{
	int		max;
	t_num	*curr;

	if (stack == NULL)
		return (0);
	max = stack->rank;
	curr = stack->next;
	while (curr != stack)
	{
		if (max < curr->rank)
			max = curr->rank;
		curr = curr->next;
	}
	if (max < curr->rank)
		max = curr->rank;
	return (max);
}

int	stack_rank_min(t_num *stack)
{
	int		min;
	t_num	*curr;

	if (stack == NULL)
		return (0);
	min = stack->rank;
	curr = stack->next;
	while (curr != stack)
	{
		if (min > curr->rank)
			min = curr->rank;
		curr = curr->next;
	}
	if (min > curr->rank)
		min = curr->rank;
	return (min);
}

int	count_stack(t_num *stack)
{
	int		count;
	t_num	*curr;

	if (stack == NULL)
		return (0);
	count = 1;
	curr = stack->next;
	while (curr != stack)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}
