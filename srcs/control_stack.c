/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:50 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 14:23:52 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_num	*bottom_stack(t_num *stack)
{
	if (stack != NULL)
		return (stack->prev);
	else
		return (NULL);
}

t_num	*num_new(int content)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (new == NULL)
		exit_on_error();
	new->content = content;
	new->rank = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	push_stack(t_num **stack, t_num *new)
{
	if (new != NULL)
	{
		if (*stack == NULL)
		{
			new->next = new;
			new->prev = new;
		}
		else
		{
			new->next = *stack;
			new->prev = (*stack)->prev;
		}
		if (*stack != NULL)
		{
			(*stack)->prev->next = new;
			(*stack)->prev = new;
		}
		*stack = new;
	}
}

t_num	*pop_stack(t_num **stack)
{
	t_num	*pop_ptr;

	pop_ptr = *stack;
	if (pop_ptr == NULL)
		return (NULL);
	if (pop_ptr == pop_ptr->next)
		*stack = NULL;
	else
	{
		pop_ptr->prev->next = pop_ptr->next;
		*stack = pop_ptr->next;
		(*stack)->prev = pop_ptr->prev;
	}
	return (pop_ptr);
}
