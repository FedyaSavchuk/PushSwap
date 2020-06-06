//
// Created by Fedya Savchuk on 06/06/2020.
//

#include "push_swap.h"

void swap(t_elem *stack) {
    int number = stack->prev->number;
    stack->prev->number = stack->number;
    stack->number = number;
}

void double_swap(t_elem *first_stack, t_elem *second_stack) {
    swap(first_stack);
    swap(second_stack);
}

void push(t_elem **from, t_elem **to) {
    t_elem *elem;
    elem = (*from);
    *from = (*from)->prev;

    if (*from) {
        (*from)->next = NULL;
    }
    elem->prev = (*to);

    if (*to) {
        (*to)->next = elem;
    }
    *to = elem;
}

void rotate(t_elem **stack_top, t_elem **stack_bottom, int reverse) {
    t_elem *prev;
    prev = (*stack_top)->prev;
    (*stack_top)->prev = NULL;
}



