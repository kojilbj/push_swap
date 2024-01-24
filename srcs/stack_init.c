/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:27:45 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/24 15:43:25 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init_a(t_num **stack, char *av)
{
	t_num	*new;

	if (*av == '\0')
		exit_on_error(*stack);
	while (*av)
	{
		if (ft_isdigit(*av))
		{
			new = num_new(ft_atoi(av));
			if (new == NULL)
				exit_on_error(*stack);
			push_stack(stack, new);
			rotate(stack);
		}
		if (*av == '-')
			av++;
		while (ft_isdigit(*av))
			av++;
		while (*av == ' ')
			av++;
		if (!ft_isdigit(*av) && *av != '\0')
			exit_on_error(*stack);
	}
	coordinate_compression(*stack);
}

void	stack_init_b(t_num **stack, char **av)
{
	t_num	*new;
	int		i;

	i = 1;
	while (av[i])
	{
		new = num_new(ft_atoi(av[i]));
		if (new == NULL)
			exit_on_error(*stack);
		while (*av[i])
		{
			if (*av[i] == '-')
				av[i]++;
			if (!ft_isdigit(*av[i]))
				exit_on_error(*stack);
			av[i]++;
		}
		push_stack(stack, new);
		rotate(stack);
		i++;
	}
	coordinate_compression(*stack);
}

void	coordinate_compression(t_num *stack)
{
	int		mini;
	int		max;
	int		i;
	int		dup_fg;
	t_num	*curr;

	if (stack == NULL)
		return ;
	mini = stack->content;
	max = stack_max(stack);
	i = 0;
	dup_fg = 0;
	while (i < count_stack(stack))
	{
		curr = stack->next;
		max = stack_max(stack);
		while (curr != stack)
		{
			if (max >= curr->prev->content && curr->prev->rank == 0)
			{
				mini = curr->prev->content;
				max = mini;
			}
			curr = curr->next;
		}
		if (max >= curr->prev->content && curr->prev->rank == 0)
		{
			mini = curr->prev->content;
			max = mini;
		}
		curr = stack->next;
		while (curr != stack)
		{
			if (mini == curr->prev->content && curr->prev->rank == 0)
			{
				curr->prev->rank = i + 1;
				if (dup_fg == 1)
					exit_on_error();
				dup_fg = 1;
			}
			curr = curr->next;
		}
		if (mini == curr->prev->content && curr->prev->rank == 0)
		{
			curr->prev->rank = i + 1;
			if (dup_fg == 1)
				exit_on_error();
		}
		i++;
		dup_fg = 0;
	}
}
