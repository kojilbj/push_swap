#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	**stack;
	int	*new;

	new = num_new(10);
	push_stack(&stack, new);
	printf("%d\n", **stack);
}

