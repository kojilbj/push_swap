/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/11 17:17:50 by kojwatan         ###   ########.fr       */
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
	stack_init(&a, av[1]);
	ft_printf("a\n");
	ft_printf("count%d\n", count_stack(a));
	print_stack(a);
	ft_printf("b\n");
	print_stack(b);
	return (0);
}
