/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:16:20 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/17 14:03:39 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_num **stack)
{
	if (*stack != NULL)
		*stack = (*stack)->prev;
}

void	reverse_rotate_a(t_num **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}


void	reverse_rotate_b(t_num **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_num **a, t_num **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
