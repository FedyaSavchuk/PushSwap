//
// Created by Fedya Savchuk on 06/06/2020.
//

#include "push_swap.h"

int ft_is_number(char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] <= '0' || str[i] >= '9') {
            return 0;
        }
        i++;
    }

    return 1;
}

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

void checker(int argc, char **argv, t_elem *stack_a, t_elem *stack_b) {
    fill_stack(argc, argv, stack_a);
}