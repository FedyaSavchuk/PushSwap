//
// Created by Fedya Savchuk on 06/06/2020.
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

int search_median(t_elem *stack) {
    int size = stack_size(stack);
    t_elem *start = stack;

    int min = stack->number;
    while (stack) {
        min = get_smaller(min, stack->number);
        stack = stack->prev;
    }

    int i = 0;
    while (i < size / 2) {
        stack = start;
        while (stack->number <= min) {
            stack = stack->prev;
        }
        int smaller = stack->number;
        while (stack) {
            if (stack->number <= min) {
                stack = stack->prev;
                continue;
            }
            smaller = get_smaller(smaller, stack->number);
            stack = stack->prev;
        }
        min = smaller;
        i++;
    }

    return min;
}

void sort(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, int median) {
    int size = stack_size(*first_stack_top);
    int i = 0;
    while (i < size && stack_size(*first_stack_top) > 3) {
        if ((*first_stack_top)->number <= median) {
            push(first_stack_top, second_stack_top);
        }
        else {
            rotate(first_stack_top, first_stack_bottom, 0);
        }
        i++;
    }
}

void median_sort(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, t_elem **second_stack_bottom) {
    while (stack_size(*first_stack_top) > 3) {
        int median = search_median(*first_stack_top);
        sort(first_stack_top, first_stack_bottom, second_stack_top, median);
    }
}







