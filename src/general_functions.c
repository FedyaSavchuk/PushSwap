//
// Created by Fedya Savchuk on 08/06/2020.
//

#include "push_swap.h"

int stack_size(t_elem *stack) {
    int size = 0;
    while (stack) {
        stack = stack->prev;
        size++;
    }
    return size;
}

int get_smaller(int first, int second) {
    return first < second ? first : second;
}

int ft_is_number(char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }

    return 1;
}

int is_sort(t_elem *first_stack_top) {
    while (first_stack_top->prev) {
        if (first_stack_top->number > first_stack_top->prev->number) {
            return 0;
        }
        first_stack_top = first_stack_top->prev;
    }
    return 1;
}

void    print_stack(t_elem *stack, char title[])
{
    write(1, title, ft_strlen(title));
    write(1, "\n", 1);
    while (stack) {
        ft_putnbr(stack->number);
        ft_putchar('\n');
        stack = stack->prev;
    }
}