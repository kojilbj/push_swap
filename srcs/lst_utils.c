/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:57:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/17 23:28:06 by kojwatan         ###   ########.fr       */
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

void	print_stack(t_num *stack)
{
	t_num	*curr;

	if (stack == NULL)
	{
		ft_printf("stack is empty\n");
		ft_printf("-----------------------\n");
		return ;
	}
	curr = stack->next;
	while (curr != stack)
	{
		ft_printf("content %d\trank %d\n", curr->prev->content, curr->prev->rank);
		curr = curr->next;
	}
	ft_printf("content %d\trank %d\n", curr->prev->content, curr->prev->rank);
	ft_printf("-----------------------\n");
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
