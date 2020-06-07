//
// Created by Fedya Savchuk on 06/06/2020.
//

# include "ft_printf.h"
# include "push_swap.h"

void    print_stacks(t_elem *stack)
{
    while (stack) {
        ft_putnbr(stack->number);
        ft_putchar('\n');
        stack = stack->prev;
    }
}

void test_swap(t_elem **p1, t_elem **p2) {
    *p1 = *p2;
}

int     main(int argc, char **argv) {
    t_elem *stack_a;
    t_elem *stack_b;
    stack_a = ft_memalloc(sizeof(t_elem));
    stack_b = ft_memalloc(sizeof(t_elem));
    test_swap(&stack_a, &stack_b);

    t_elem *stack_top;
    t_elem *stack_bottom;

    checker(argc, argv, stack_a, stack_b);

    stack_bottom = stack_a;
    stack_top = stack_a;

    while (stack_top->next) {
        stack_top = stack_top->next;
    }
    stack_b = NULL;


    //rotate(&stack_top, &stack_bottom, 1);
    //rotate(&stack_top, &stack_bottom, 1);
    print_stacks(stack_top);

    return 0;
}

