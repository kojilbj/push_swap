/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/30 17:01:06 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(void)
{
	t_num	**stack;
	t_num	*num1;
	t_num	*num2;

	stack = NULL;
	*stack = NULL;
	num1 = num_new(10);
	ft_printf("aa\n");
	num_push(stack, num1);
	num2 = num_new(20);
	num_push(stack, num2);
	return (0);
}
