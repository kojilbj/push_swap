/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:01:14 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/23 13:10:21 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_num **a, t_num **b)
{
	int	count;

	count = count_stack(*a);
	if (count == 1 || is_sorted(*a))
		return ;
	else if (count < 4)
		sort_a_ascending(a);
	else if (count < 7)
		sort_426(a, b);
	else
		quick_sort(a, b);
}

void	sort_426(t_num **a, t_num **b)
{
	int	mini_rank;

	mini_rank = 1;
	while (count_stack(*a) > 3)
	{
		if ((*a)->rank == mini_rank)
		{
			push_b(b, a);
			mini_rank++;
		}
		else if ((*a)->prev->rank == mini_rank)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
	sort_a_ascending(a);
	while (count_stack(*b) > 0)
		push_a(a, b);
}
