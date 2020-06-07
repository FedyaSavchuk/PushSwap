//
// Created by Fedya Savchuk on 06/06/2020.
//

# include "ft_printf.h"
# include "push_swap.h"

void    print_stacks(t_elem *stack)
{
    write(1, "PRINT STACK\n", 12);
    while (stack) {
        ft_putnbr(stack->number);
        ft_putchar('\n');
        stack = stack->prev;
    }
}

int     main(int argc, char **argv) {
    t_elem *stack_a;
    t_elem *stack_b;
    stack_a = ft_memalloc(sizeof(t_elem));

    t_elem *stack_top_a;
    t_elem *stack_bottom_a;

    t_elem *stack_top_b;
    t_elem *stack_bottom_b;

    checker(argc, argv, stack_a, stack_b);

    stack_bottom_a = stack_a;
    stack_top_a = stack_a;

    stack_bottom_b = stack_b;
    stack_top_b = stack_b;

    while (stack_top_a->next) {
        stack_top_a = stack_top_a->next;
    }
    stack_b = NULL;
    median_sort(&stack_top_a, &stack_bottom_a, &stack_top_b, &stack_bottom_b);
    print_stacks(stack_top_a);
    print_stacks(stack_top_b);

    return 0;
}

