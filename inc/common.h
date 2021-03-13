#ifndef COMMON_H
# define COMMON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // delete
#include "libft.h"

typedef struct s_data
{
    int data;
    struct s_data *next;
}              t_data;

typedef struct s_stack
{
    t_data *a;
    t_data *b;
}              t_stack;

/*
** COMMON
*/
t_stack    *get_stack_data(int ac, char **av);
void    clean_all(t_stack *stacks);

/*
** COMMON - OPERATION
*/
void    op_sa(t_stack *stacks);
void    op_sb(t_stack *stacks);
void    op_ss(t_stack *stacks);
void    op_pa(t_stack *stacks);
void    op_pb(t_stack *stacks);
void    op_ra(t_stack *stacks);
void    op_rb(t_stack *stacks);
void    op_rr(t_stack *stacks);
void    op_rra(t_stack *stacks);
void    op_rrb(t_stack *stacks);
void    op_rrr(t_stack *stacks);

/*
** LIST FUNCTION
*/
void	lstadd_back(t_data **alst, t_data *new);
void	lstadd_front(t_data **alst, t_data *new);
void	lstclear(t_data **lst);
void	lstdelone(t_data *lst);
t_data	*lstlast(t_data *lst);
t_data	*lstnew(int data);
int	lstsize(t_data *lst);

#endif