//
// Created by Fedya Savchuk on 06/06/2020.
//

# include "ft_printf.h"
# include "push_swap.h"

void add_number(t_elem *stack_a, int number) {
    t_elem *prev_elem;

    if (!stack_a->number) {
        stack_a->number = number;
    }
    else {
        while (stack_a) {
            prev_elem = stack_a;
            stack_a = stack_a->next;
        }
        stack_a = ft_memalloc(sizeof(t_elem));
        stack_a->number = number;
        prev_elem->next = stack_a;
        stack_a->prev = prev_elem;
    }
}

void fill_stack(int argc, char **argv, t_elem *stack_a) {
    int i = 1;

    while (i < argc) {
        if (!ft_is_number(argv[i])) {
            ft_printf("ERROR");
            return;
        }

        add_number(stack_a, ft_atoi(argv[i]));
        i++;
    }
}

int     main(int argc, char **argv) {
    counter = 0;
    t_elem *stack_a;
    t_elem *stack_b;
    t_elem *stack_top_a;
    t_elem *stack_bottom_a;
    t_elem *stack_top_b;
    t_elem *stack_bottom_b;

    stack_a = ft_memalloc(sizeof(t_elem));
    stack_b = NULL;

    fill_stack(argc, argv, stack_a);

    stack_bottom_a = stack_a;
    stack_top_a = stack_a;
    stack_bottom_b = stack_b;
    stack_top_b = stack_b;

    while (stack_top_a->next) {
        stack_top_a = stack_top_a->next;
    }

    median_sort(&stack_top_a, &stack_bottom_a, &stack_top_b, &stack_bottom_b);
    sort_stack(&stack_top_a, &stack_bottom_a, &stack_top_b, &stack_bottom_b);

    return 0;
}

