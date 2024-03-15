/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:44:09 by kojwatan          #+#    #+#             */
/*   Updated: 2024/03/16 00:07:20 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validate_char(char c)
{
	if (c == '+' || c == ' ' || c == '-' || ('0' <= c && c <= '9'))
		return (1);
	else
		return (-1);
}

int	validate_duplicate_util(t_num *stack, int check_rank)
{
	t_num	*curr;

	curr = stack->next;
	while (curr != stack)
	{
		if (curr->rank == check_rank)
			return (-1);
		curr = curr->next;
	}
	return (1);
}

int	validate_duplicate(t_num *stack)
{
	t_num	*curr;

	if (stack == NULL)
		return (-1);
	curr = stack->next;
	while (curr != stack)
	{
		if (validate_duplicate_util(curr, curr->rank) == -1)
			return (-1);
		curr = curr->next;
	}
	return (1);
}

int	empty_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (-1);
}

int	validate(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		if (empty_check(av[i]) == -1)
			return (-1);
		while (av[i][j] != '\0')
		{
			while (av[i][j] != '\0' && av[i][j] == ' ')
				j++;
			if (validate_atoi(&av[i][j]) == -1)
				return (-1);
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			while (av[i][j] != '\0' && ft_isdigit(av[i][j]))
				j++;
		}
		i++;
	}
	return (1);
}
