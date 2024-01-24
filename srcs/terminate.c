/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:32 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 14:19:39 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_on_error(t_num *stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_stack(t_num *stack)
{
	t_num	*curr;
	int	count;
	int	i;

	i = 0;
	count = count_stack(stack);
	curr = stack;
	while (i < count - 1)
	{
		free(curr->prev);
		curr = curr->next;
		i++;
	}
}
