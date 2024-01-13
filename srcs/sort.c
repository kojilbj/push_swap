/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:01:14 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/11 22:38:58 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_num **stack)
{
	if (count_stack(*stack) < 4)
		sort_a(stack);
}

void	sort_a(t_num **stack)
{
	int	i;
	t_num	*top;
	t_num	*bottom;

	i = 0;
	top = *stack;
	bottom = bottom_stack(top);
	while (i < 3)
	{
		if (top->content < top->next->content)
			swap_a(stack);
		top = *stack;
		bottom = bottom_stack(top);
		if (top->content < bottom->content)
			rotate_a(stack);
		i++;
	}
}
