/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:27:45 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/30 01:30:48 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init_util(t_num **stack, char *av)
{
	t_num	*new;

	new = num_new(ft_atoi(av));
	if (new == NULL)
		exit_on_error(*stack, NULL, NULL);
	push_stack(stack, new);
	rotate(stack);
}

void	stack_init(t_num **stack, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while (av[i][j] != '\0' && av[i][j] == ' ')
				j++;
			if (av[i][j] != '\0')
				stack_init_util(stack, &av[i][j]);
			if (av[i][j] == '-')
				j++;
			while (av[i][j] != '\0' && ft_isdigit(av[i][j]))
				j++;
		}
		i++;
	}
	coordinate_compression(*stack);
}
