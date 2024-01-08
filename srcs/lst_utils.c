/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:57:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/08 22:35:03 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_num	*num_new(int content)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	push_stack(t_num **stack, t_num *new)
{
	new->next = *stack;
	*stack = new;
}

t_num	*pop_stack(t_num **stack)
{
	t_num	*pop_ptr;

	pop_ptr = *stack;
	if (pop_ptr != NULL)
		*stack = pop_ptr->next;
	return (pop_ptr);
}
