
#include "push_swap.h"

void	swap(t_elem *stack)
{
	int number;

	number = stack->prev->number;
	stack->prev->number = stack->number;
	stack->number = number;
}

void	double_swap(t_elem *first_stack, t_elem *second_stack)
{
	swap(first_stack);
	swap(second_stack);
}

void	push(t_elem **from, t_elem **to)
{
	t_elem *elem;

	elem = (*from);
	*from = (*from)->prev;
	if (*from)
	{
		(*from)->next = NULL;
	}
	elem->prev = (*to);
	if (*to)
	{
		(*to)->next = elem;
	}
	*to = elem;
}

void	rotate(t_elem **stack_top, t_elem **stack_bottom, int reverse)
{
	t_elem *elem;

	if (reverse)
	{
		elem = (*stack_bottom)->next;
		elem->prev = NULL;
		(*stack_top)->next = *stack_bottom;
		(*stack_bottom)->prev = *stack_top;
		(*stack_bottom)->next = NULL;
		*stack_top = *stack_bottom;
		*stack_bottom = elem;
	}
	else
	{
		elem = (*stack_top)->prev;
		(*stack_top)->next = *stack_bottom;
		(*stack_top)->prev = NULL;
		(*stack_bottom)->prev = *stack_top;
		elem->next = NULL;
		*stack_bottom = *stack_top;
		*stack_top = elem;
	}
}

void	double_rotate(t_elem **first_stack_top, t_elem **first_stack_bottom, t_elem **second_stack_top, t_elem **second_stack_bottom, int reverse)
{
	rotate(first_stack_top, first_stack_bottom, reverse);
	rotate(second_stack_top, second_stack_bottom, reverse);
}
