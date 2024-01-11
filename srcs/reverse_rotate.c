/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:16:20 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/09 18:27:18 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_num **stack)
{
	t_num	*bottom;
	t_num	*new_bottom;

	bottom = *stack;
	new_bottom = *stack;
	while (bottom->next != NULL)
	{
		new_bottom = bottom;
		bottom = bottom->next;
	}
	new_bottom->next = NULL;
	bottom->next = *stack;
	*stack = bottom;
}

void	reverse_rotate_a(t_num **a)
{
	reverse_rotate(a);
	ft_printf("rra");
}


void	reverse_rotate_b(t_num **b)
{
	reverse_rotate(b);
	ft_printf("rrb");
}

void	reverse_rotate_ab(t_num **a, t_num **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr");
}
