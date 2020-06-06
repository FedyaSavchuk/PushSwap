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

    checker(argc, argv, stack_a, stack_b);
    while (stack_a->next) {
        stack_a = stack_a->next;
    }
    stack_b = NULL;
    push(&stack_a, &stack_b);
    print_stacks(stack_a);
    print_stacks(stack_b);
    push(&stack_b, &stack_a);
    print_stacks(stack_a);
    print_stacks(stack_b);
    rotate(&stack_a, &stack_a, 0);

    return 0;
}

