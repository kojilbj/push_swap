/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:55:46 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/18 15:29:12 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_on_error(void)
{
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
