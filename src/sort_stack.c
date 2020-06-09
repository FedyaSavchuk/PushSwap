//
// Created by Fedya Savchuk on 07/06/2020.
//

#include "push_swap.h"

int search_position(t_elem *stack_top, int target, int stack) {
    int size = stack_size(stack_top);

    int i = 0;
    int cost = 0;
    while (i < size) {
        if ((stack == 1 && target < stack_top->number) || (stack == 2 && target == stack_top->number)) {
            break;
        }
        stack_top = stack_top->prev;
        if (i == size / 2 && cost > 0) {
            if (size % 2 != 0) {
                cost++;
            }


            cost = cost * -1;
        }
        cost++;
        i++;
    }
    return cost;
}

int search_cheaper(t_elem *first_stack_top, t_elem *first_stack_bottom, t_elem *second_stack_top, t_elem *second_stack_bottom) {
    int size = stack_size(second_stack_top);
    int i = 0;
    int min_cost;
    int target = second_stack_top->number;

    t_elem *save_top;
    save_top = second_stack_top;
    while (i < size) {
        int first_position = search_position(first_stack_top, second_stack_top->number, 1);
        int second_position = search_position(save_top, second_stack_top->number, 2);
        int full_cost = ABS(first_position) + ABS(second_position);
        if (first_position > 0 && second_position > 0) {
            first_position--;
            second_position--;
            full_cost--;
        }
        else if (first_position < 0 && second_position < 0) {
            first_position++;
            second_position++;
            full_cost--;
        }

        if (i == 0) {
            min_cost = full_cost;
        }
        if (full_cost < min_cost) {
            min_cost = full_cost;
            target = second_stack_top->number;
        }

        i++;
        second_stack_top = second_stack_top->prev;
    }

    return target;
}

void ssort(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, t_elem **second_stack_bottom, int target) {
    int first_position = search_position(*first_stack_top, target, 1);
    int second_position = search_position(*second_stack_top, target, 2);

    while (first_position < 0 && second_position < 0) {
        counter++;
        double_rotate(first_stack_top, first_stack_bottom, second_stack_top, second_stack_bottom, 1);
        first_position++;
        second_position++;
    }
    while (first_position > 0 && second_position > 0) {
        counter++;
        double_rotate(first_stack_top, first_stack_bottom, second_stack_top, second_stack_bottom, 0);
        first_position--;
        second_position--;
    }

    while (first_position < 0) {
        counter++;
        rotate(first_stack_top, first_stack_bottom, 1);
        first_position++;
    }
    while (second_position < 0) {
        counter++;
        rotate(second_stack_top, second_stack_bottom, 1);
        second_position++;
    }

    while (first_position > 0) {
        counter++;
        rotate(first_stack_top, first_stack_bottom, 0);
        first_position--;
    }
    while (second_position > 0) {
        counter++;
        rotate(second_stack_top, second_stack_bottom, 0);
        second_position--;
    }

    while ((*first_stack_bottom)->number > target && (*first_stack_bottom)->number < (*first_stack_top)->number) {
        counter++;
        rotate(first_stack_top, first_stack_bottom, 1);
    }
    push(second_stack_top, first_stack_top);
}

void sort_stack(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, t_elem **second_stack_bottom) {
    if (!is_sort(*first_stack_top)) {
        counter++;
        rotate(first_stack_top, first_stack_bottom, 0);
    }


    while (*second_stack_top) {
        int target = search_cheaper(*first_stack_top, *first_stack_bottom, *second_stack_top, *second_stack_bottom);
        ssort(first_stack_top, first_stack_bottom, second_stack_top, second_stack_bottom, target);
        print_stack(*first_stack_top, "First Stack");
        //print_stack(*second_stack_top, "Second Stack");
    }

    while (!is_sort(*first_stack_top)) {
        counter++;
        if ((*first_stack_top)->number > (*first_stack_bottom)->number) {
            rotate(first_stack_top, first_stack_bottom, 0);
        }
        else {
            rotate(first_stack_top, first_stack_bottom, 1);
        }

    }

    print_stack(*first_stack_top, "First Stack");
    print_stack(*second_stack_top, "Second Stack");
    ft_putnbr(counter);
}
