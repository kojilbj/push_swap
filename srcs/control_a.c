/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 03:21:34 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 15:40:58 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_ascending_util(t_num **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->rank;
	middle = (*stack)->next->rank;
	bottom = (*stack)->prev->rank;
	if (top < middle && bottom < middle)
		reverse_rotate_a(stack);
	else if (middle < top && bottom < top)
		rotate_a(stack);
	else if (middle < top)
		swap_a(stack);
}

void	sort_a_ascending(t_num **stack)
{
	int	i;

	i = 0;
	if (count_stack(*stack) == 1)
		return ;
	while (i < 2)
	{
		sort_a_ascending_util(stack);
		i++;
	}
}
