/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/05 21:17:20 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(void)
{
	t_num	*stack;
	t_num	*num;

	stack = NULL;
	num = num_new(0);
	push_stack(&stack, num);
	num = num_new(10);
	push_stack(&stack, num);
	ft_printf("%d\n", stack->content);
	pop_stack(&stack);
	return (0);
}
