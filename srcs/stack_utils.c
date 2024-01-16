/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:08:15 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/15 02:50:53 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_max(t_num *stack)
{
	int	max;
	t_num	*curr;

	max = stack->content;
	curr = stack;
	while (curr != NULL)
	{
		if (max < curr->content)
			max = curr->content;
		curr = curr->next;
	}
	return (max);
}

void	coordinate_compression(t_num *stack)
{
	int	mini;
	int	max;
	int	i;
	t_num	*curr;

	curr = stack;
	mini = curr->content;
	max = stack_max(stack);
	i = 0;
	while (i < count_stack(stack))
	{
		curr = stack;
		max = stack_max(stack);
		while (curr != NULL)
		{
			if (max >= curr->content && curr->rank == 0)
			{
				mini = curr->content;
				max = mini;
			}
			curr = curr->next;
		}
		curr = stack;
		while (curr != NULL)
		{
			if (mini == curr->content && curr->rank == 0)
				curr->rank = i + 1;
			curr = curr->next;
		}
		i++;
	}
}

int	count_stack(t_num *stack)
{
	int		i;
	t_num	*curr;

	i = 0;
	curr = stack;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	stack_init_a(t_num **stack, char *av)
{
	t_num	*new;

	if (*av == '\0')
		exit_on_error();
	while (*av)
	{
		if (ft_isdigit(*av))
		{
			new = num_new(ft_atoi(av));
			if (new == NULL)
				exit_on_error();
			push_stack(stack, new);
		}
		while (ft_isdigit(*av))
			av++;
		while (*av == ' ')
			av++;
		if (!ft_isdigit(*av) && *av != '\0')
			exit_on_error();
	}
	coordinate_compression(*stack);
}

void	stack_init_b(t_num **stack, char **av)
{
	t_num	*new;
	int	i;

	i = 1;
	while (av[i])
	{
		new = num_new(ft_atoi(av[i]));
		if (new == NULL)
			exit_on_error();
		while (*av[i])
		{
			if (!ft_isdigit(*av[i]))
				exit_on_error();
			av[i]++;
		}
		push_stack(stack, new);
		i++;
	}
	coordinate_compression(*stack);
}
