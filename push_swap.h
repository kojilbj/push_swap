# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_num
{
	int		content;
	struct s_num		*next;
}	t_num;

//lst_util.c
t_num	*num_new(int conent);
void	push_stack(t_num **stack, t_num *new);
t_num	*pop_stack(t_num **stack);

# endif
