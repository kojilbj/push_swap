/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:11:21 by kojwatan          #+#    #+#             */
/*   Updated: 2024/01/30 01:32:21 by kojwatan         ###   ########.fr       */
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
	if (validate(av, ac) == -2)
		return (0);
	if (validate(av, ac) == -1)
		exit_on_error(NULL, NULL, NULL);
	stack_init(&a, av);
	if (validate_duplicate(a) == -1)
		exit_on_error(a, NULL, NULL);
	sort(&a, &b);
	free_stack(a);
	return (0);
}
