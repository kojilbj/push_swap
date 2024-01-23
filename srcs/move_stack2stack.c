/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack2stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:18:38 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/22 01:06:56 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	move_a2b(t_num **a, t_num **b, int pivot_a, int sorted_pivot)
{
	if (sorted_pivot + 1 == (*a)->rank)
	{
		rotate_a(a);
		return ;
	}
	while (less_than_pivot_check(*a, pivot_a, sorted_pivot))
	{
		if ((*a)->rank <= pivot_a && (*a)->rank > sorted_pivot)
			push_b(b, a);
		else
			rotate_a(a);
	}
}

void	move_b2a(t_num **a, t_num **b, int pivot_b)
{
	while (greater_than_pivot_check(*b, pivot_b))
	{
		if ((*b)->rank > pivot_b)
			push_a(a, b);
		else
			rotate_b(b);
	}
}
