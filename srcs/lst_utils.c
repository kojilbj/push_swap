/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:57:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/16 19:20:15 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_num	*bottom_stack(t_num *stack)
{
	t_num	*bottom;

	bottom = stack;
	while (bottom->next != NULL)
		bottom = bottom->next;
	return (bottom);
}

void	print_stack(t_num *stack)
{
	t_num	*num;

	num = stack;
	while (num != NULL)
	{
		ft_printf("content %d\trank %d\n", num->content, num->rank);
		num = num->next;
	}
	ft_printf("%p\n", num);
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
	if (pop_ptr != NULL)
	{
		*stack = pop_ptr->next;
		(*stack)->prev = pop_ptr->prev;
	}
	return (pop_ptr);
}
