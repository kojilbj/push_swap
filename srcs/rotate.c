/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:15:35 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/09 18:16:04 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_num **stack)
{
	t_num	*top;
	t_num	*curr;

	top = *stack;
	*stack = top->next;
	top->next = NULL;
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = top;
}

void	rotate_a(t_num **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_num **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_ab(t_num **a, t_num **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
