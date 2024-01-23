/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:13:01 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/17 14:47:45 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_num **stack)
{
	t_num	*top;
	t_num	*second;

	top = pop_stack(stack);
	second = pop_stack(stack);
	if (top != NULL)
		push_stack(stack, top);
	if (second != NULL)
		push_stack(stack, second);
}

void	swap_a(t_num **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_num **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_ab(t_num **a, t_num **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
