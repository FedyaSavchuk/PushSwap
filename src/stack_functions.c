/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:11:08 by fedyasavchuk      #+#    #+#             */
/*   Updated: 2020/06/10 17:11:08 by fedyasavchuk     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_elem **stack, char *command)
{
	int number;

	if (!(*stack) || stack == NULL)
		return ;
	number = (*stack)->prev->number;
	(*stack)->prev->number = (*stack)->number;
	(*stack)->number = number;
	ft_putstr(command);
}

void	double_swap(t_elem **first_stack, t_elem **second_stack, char *command)
{
	ft_putstr(command);
	swap(first_stack, "");
	swap(second_stack, "");
}

void	push(t_elem *stack_a[], t_elem *stack_b[], char *command)
{
	t_elem *elem;

	if (!(stack_a[0]))
		return ;
	elem = (stack_a[0]);
	stack_a[0] = (stack_a[0])->prev;
	if (stack_a[0])
		(stack_a[0])->next = NULL;
	elem->prev = (stack_b[0]);
	if (stack_b[0])
		(stack_b[0])->next = elem;
	stack_b[0] = elem;
	if (stack_b[1] == NULL)
		stack_b[1] = stack_b[0];
	ft_putstr(command);
}

void	rotate(t_elem **stack_top, t_elem **stack_bottom,
		int reverse, char *command)
{
	t_elem *elem;

	if (!(*stack_top))
		return ;
	ft_putstr(command);
	if (reverse)
	{
		elem = (*stack_bottom)->next;
		elem->prev = NULL;
		(*stack_top)->next = *stack_bottom;
		(*stack_bottom)->prev = *stack_top;
		(*stack_bottom)->next = NULL;
		*stack_top = *stack_bottom;
		*stack_bottom = elem;
		return ;
	}
	elem = (*stack_top)->prev;
	(*stack_top)->next = *stack_bottom;
	(*stack_top)->prev = NULL;
	(*stack_bottom)->prev = *stack_top;
	elem->next = NULL;
	*stack_bottom = *stack_top;
	*stack_top = elem;
}

void	double_rotate(t_elem *stack_a[], t_elem *stack_b[],
		int reverse, char *command)
{
	ft_putstr(command);
	rotate(&stack_a[0], &stack_a[1], reverse, "");
	rotate(&stack_b[0], &stack_b[1], reverse, "");
}
