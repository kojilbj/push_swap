/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/13 16:46:10 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char *av[])
{
	t_num	*a;
//	t_num	*b;

	if (ac < 2)
		return (0);
	a = NULL;
//	b = NULL;
	if (ac == 2)
		stack_init_a(&a, av[1]);
	else
		stack_init_b(&a, av);
	ft_printf("a\n");
	print_stack(a);
	if (count_stack(a) > 1)
		sort(&a);
	print_stack(a);
//	ft_printf("b\n");
//	print_stack(b);
	return (0);
}
