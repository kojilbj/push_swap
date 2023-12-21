# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_lstnum
{
	int		content;
	void	*next;
}	t_lstnum;

//lst_util.c
t_lstnum	*ft_lstnumnew(int conent);
# endif
