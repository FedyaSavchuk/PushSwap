#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf.h"

typedef struct      s_elem
{
    int             number;
    struct s_elem   *next;
    struct s_elem   *prev;
}                   t_elem;

void checker(int argc, char **argv, t_elem *stack_a, t_elem *stack_b);
void rotate(t_elem **stack_top, t_elem **stack_bottom, int reverse);
void double_swap(t_elem *first_stack, t_elem *second_stack);
void median_sort(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, t_elem **second_stack_bottom);
void push(t_elem **from, t_elem **to);
void swap(t_elem *stack);

#endif