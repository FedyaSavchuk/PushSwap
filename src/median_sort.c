/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:10:31 by fedyasavchuk      #+#    #+#             */
/*   Updated: 2020/06/10 17:10:31 by fedyasavchuk     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_min(t_elem **stack)
{
	int min;

	min = (*stack)->number;
	while (*stack)
	{
		min = get_smaller(min, (*stack)->number);
		(*stack) = (*stack)->prev;
	}
	return (min);
}

int		search_median(t_elem *stack)
{
	int		size;
	int		min;
	int		i;
	int		smaller;
	t_elem	*start;

	start = stack;
	size = stack_size(stack);
	min = search_min(&stack);
	i = -1;
	while (++i < size / 2)
	{
		stack = start;
		while (stack->number <= min)
			stack = stack->prev;
		smaller = stack->number;
		while (stack)
		{
			if (stack->number >= min)
				smaller = get_smaller(smaller, stack->number);
			stack = stack->prev;
		}
		min = smaller;
	}
	return (min);
}

void	sort(t_elem **a_top, t_elem **a_bottom, t_elem **b_top, int median)
{
	int size;
	int i;

	i = 0;
	size = stack_size(*a_top);
	while (i < size && stack_size(*a_top) > 2)
	{
		if ((*a_top)->number > median)
			rotate(a_top, a_bottom, 0);
		else
			push(a_top, b_top);
		i++;
	}
}

void	median_sort(t_elem **a_top, t_elem **a_bottom,
					t_elem **b_top, t_elem **b_bottom)
{
	int median;

	while (stack_size(*a_top) > 2)
	{
		median = search_median(*a_top);
		sort(a_top, a_bottom, b_top, median);
	}
	*b_bottom = *b_top;
	while ((*b_bottom)->prev)
	{
		*b_bottom = (*b_bottom)->prev;
	}
}
