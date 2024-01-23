/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/21 23:18:19 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char *av[])
{
	t_num	*a;
	t_num	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (ac == 2)
		stack_init_a(&a, av[1]);
	else
		stack_init_b(&a, av);
	sort(&a, &b);
	free_stack(a);
	return (0);
}
