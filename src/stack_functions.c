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
    t_elem *new_elem;
    new_elem = ft_memalloc(sizeof(t_elem));
    new_elem->number = (*from)->number;

    *from = (*from)->prev;
    if (*from) {
        free((*from)->next);
    }

    if (*to) {
        new_elem->prev = *to;
        *to = (*to)->next;
    }
    *to = new_elem;
}

