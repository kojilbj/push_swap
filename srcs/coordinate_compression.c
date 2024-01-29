/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:26:17 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/29 22:48:08 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_min(t_num *stack)
{
	int		max;
	int		min;
	t_num	*curr;

	max = stack_max(stack);
	curr = stack->next;
	while (curr != stack)
	{
		if (max >= curr->prev->content && curr->prev->rank == 0)
		{
			min = curr->prev->content;
			max = min;
		}
		curr = curr->next;
	}
	if (max >= curr->prev->content && curr->prev->rank == 0)
	{
		min = curr->prev->content;
		max = min;
	}
	return (min);
}

void	assign_rank(t_num *stack, int min, int i)
{
	t_num	*curr;

	curr = stack->next;
	while (curr != stack)
	{
		if (min == curr->prev->content && curr->prev->rank == 0)
			curr->prev->rank = i + 1;
		curr = curr->next;
	}
	if (min == curr->prev->content && curr->prev->rank == 0)
		curr->prev->rank = i + 1;
}

void	coordinate_compression(t_num *stack)
{
	int		min;
	int		i;

	if (stack == NULL)
		return ;
	i = 0;
	while (i < count_stack(stack))
	{
		min = search_min(stack);
		assign_rank(stack, min, i);
		i++;
	}
}
