# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_num
{
	int		content;
	struct s_num		*next;
}	t_num;

//lst_util.c
int	count_stack(t_num *stack);
t_num	*bottom_stack(t_num *stack);
void	stack_init_a(t_num **stakc, char *av);
void	stack_init_b(t_num **stakc, char **av);
void	print_stack(t_num *stack);
t_num	*num_new(int conent);
void	push_stack(t_num **stack, t_num *new);
t_num	*pop_stack(t_num **stack);

//swap.c
void	swap(t_num **stack);
void	swap_a(t_num **a);
void	swap_b(t_num **b);
void	swap_ab(t_num **a, t_num **b);

//push.c
void	push_a(t_num **a, t_num **b);
void	push_b(t_num **b, t_num **a);

//rotate.c
void	rotate(t_num **stack);
void	rotate_a(t_num **a);
void	rotate_b(t_num **b);
void	rotate_ab(t_num **a, t_num **b);

//reverse_rotate.c
void	reverse_rotate(t_num **stack);
void	reverse_rotate_a(t_num **a);
void	reverse_rotate_b(t_num **b);
void	reverse_rotate_ab(t_num **a, t_num **b);

//sort.c
void	sort(t_num **stack);
void	sort_a(t_num **stack);

# endif
