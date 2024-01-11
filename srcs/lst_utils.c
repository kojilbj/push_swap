/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:57:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:16 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_num **stack, char *av)
{
	t_num	*new;

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
		while (*av == ' ')
			av++;
	}
}

int		count_stack(t_num *stack)
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
