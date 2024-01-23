/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:44:18 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/21 13:56:15 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pivot	*new_pivot(int pivot)
{
	t_pivot	*new;

	new = malloc(sizeof(t_num));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->pivot = pivot;
	return (new);
}

void	push_pivot_stack(t_pivot **stack, t_pivot *new)
{
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

t_pivot	*pop_pivot_stack(t_pivot **stack)
{
	t_pivot	*pop_ptr;

	if (*stack == NULL)
		return NULL;
	pop_ptr = *stack;
	*stack = (*stack)->next;
	return (pop_ptr);
}
