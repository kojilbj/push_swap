#include "../push_swap.h"

int	main(int ac, char *av[])
{
	t_num	*stack;

	if (ac < 2)
		exit_on_error();
	stack = NULL;
	if (ac == 2)
		stack_init_a(&stack, av[1]);
	else
		stack_init_b(&stack, av);
	return (0);
}
