/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:32 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/30 01:40:49 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_on_error(t_num *a, t_num *b, t_pivot *pivot_stack)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
	if (pivot_stack != NULL)
		free_pivot_stack(pivot_stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_stack(t_num *stack)
{
	t_num	*top;

	top = stack;
	while (top != NULL)
	{
		top = pop_stack(&stack);
		free(top);
	}
}

void	free_pivot_stack(t_pivot *stack)
{
	t_pivot	*top;

	top = stack;
	while (top != NULL)
	{
		top = pop_pivot_stack(&stack);
		free(top);
	}
}
