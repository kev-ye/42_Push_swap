#ifndef COMMON_H
# define COMMON_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // delete
#include "libft.h"

# define OP_AMOUT 11

typedef struct s_stack
{
    t_list *a;
    t_list *b;
}              t_stack;

typedef struct s_op
{
    const char *name;
    void    (*f)();
}              t_op;


/*
** COMMON
*/
t_stack    *get_stack_data(int ac, char **av);
void    clean_all(t_stack *stacks, char *line);
void    print_stack(t_list *a, t_list *b);

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

#endif