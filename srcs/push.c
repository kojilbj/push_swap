/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:14:46 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 15:38:53 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_num **a, t_num **b)
{
	t_num	*data;

	data = pop_stack(b);
	push_stack(a, data);
	ft_printf("pa\n");
}

void	push_b(t_num **b, t_num **a)
{
	t_num	*data;

	data = pop_stack(a);
	push_stack(b, data);
	ft_printf("pb\n");
}
