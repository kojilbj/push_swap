/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:57:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/13 16:48:45 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init_a(t_num **stack, char *av)
{
	t_num	*new;

	if (*av == '\0')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
	while (*av)
	{
		if (ft_isdigit(*av))
		{
			new = num_new(ft_atoi(av));
			if (new == NULL)
				exit(EXIT_FAILURE);
			push_stack(stack, new);
		}
		while (ft_isdigit(*av))
			av++;
		if (!ft_isdigit(*av) && *av != '\0')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		while (*av == ' ')
			av++;
	}
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
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		while (*av[i])
		{
			if (!ft_isdigit(*av[i]))
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			av[i]++;
		}
		push_stack(stack, new);
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
		ft_printf("%d\n", num->content);
		num = num->next;
	}
	ft_printf("%p\n", num);
}

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
	if (new != NULL)
	{
		new->next = *stack;
		*stack = new;
	}
}

t_num	*pop_stack(t_num **stack)
{
	t_num	*pop_ptr;

	pop_ptr = *stack;
	if (pop_ptr != NULL)
		*stack = pop_ptr->next;
	return (pop_ptr);
}
