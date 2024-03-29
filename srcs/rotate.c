/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:15:35 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/17 14:02:47 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_num **stack)
{
	if (*stack != NULL)
		*stack = (*stack)->next;
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
