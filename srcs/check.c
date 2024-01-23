/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:15:34 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/21 16:17:55 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	less_than_pivot_check(t_num *stack, int pivot, int sorted_pivot)
{
	t_num	*curr;

	if (stack == NULL)
		return (0);
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->prev->rank <= pivot && curr->prev->rank > sorted_pivot)
			return (1);
		curr = curr->next;
	}
	if (curr->prev->rank <= pivot && curr->prev->rank > sorted_pivot)
		return (1);
	return (0);
}

int	greater_than_pivot_check(t_num *stack, int pivot)
{
	t_num	*curr;

	curr = stack->next;
	while (curr != stack)
	{
		if (curr->prev->rank > pivot)
			return (1);
		curr = curr->next;
	}
	if (curr->prev->rank > pivot)
		return (1);
	return (0);
}

int	is_sorted(t_num *stack)
{
	t_num	*curr;

	if (stack->rank != 1)
		return (0);
	curr = stack->next;
	while (curr != stack)
	{
		if (!(curr->rank == curr->prev->rank + 1))
			return (0);
		curr = curr->next;
	}
	return (1);
}
