/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:10:57 by fedyasavchuk      #+#    #+#             */
/*   Updated: 2020/06/10 17:10:57 by fedyasavchuk     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_position(t_elem *stack_top, int target, int stack)
{
	int i;
	int cost;
	int size;

	i = 0;
	cost = 0;
	size = stack_size(stack_top);
	while (i < size)
	{
		if (stack == 1 && target < stack_top->number)
			break ;
		if (stack == 2 && target == stack_top->number)
			break ;
		stack_top = stack_top->prev;
		if (i == size / 2 && cost > 0)
		{
			if (size % 2 != 0)
				cost++;
			cost = cost * -1;
		}
		cost++;
		i++;
	}
	return (cost);
}

int		get_full_cost(t_elem *a_top, t_elem *b_top, t_elem *save_top)
{
	int	full_cost;
	int	a_position;
	int	b_position;

	a_position = search_position(a_top, b_top->number, 1);
	b_position = search_position(save_top, b_top->number, 2);
	full_cost = ABS(a_position) + ABS(b_position);
	if (a_position > 0 && b_position > 0 && a_position-- && b_position--)
		full_cost--;
	else if (a_position < 0 && b_position < 0 && a_position++ && b_position++)
		full_cost--;
	return (full_cost);
}

int		search_cheaper(t_elem *a_top, t_elem *b_top, int i)
{
	int		size;
	int		min_cost;
	int		full_cost;
	t_elem	*save_top;
	int		target;

	save_top = b_top;
	target = b_top->number;
	size = stack_size(b_top);
	while (i < size)
	{
		full_cost = get_full_cost(a_top, b_top, save_top);
		if (i == 0)
			min_cost = full_cost;
		if (full_cost < min_cost)
		{
			min_cost = full_cost;
			target = b_top->number;
		}
		i++;
		b_top = b_top->prev;
	}
	return (target);
}

void	ssort(t_elem **stack_a[], t_elem **stack_b[], int target)
{
	int	p1;
	int	p2;

	p1 = search_position(*stack_a[0], target, 1);
	p2 = search_position(*stack_b[0], target, 2);
	while (p1 < 0 && p2 < 0 && p1++ && p2++)
		double_rotate(*stack_a, *stack_b, 1, "rrr\n");
	while (p1 > 0 && p2 > 0 && p1-- && p2--)
		double_rotate(*stack_a, *stack_b, 0, "rr\n");
	while (p1 < 0 && p1++)
		rotate(stack_a[0], stack_a[1], 1, "rra\n");
	while (p2 < 0 && p2++)
		rotate(stack_b[0], stack_b[1], 1, "rrb\n");
	while (p1 > 0 && p1--)
		rotate(stack_a[0], stack_a[1], 0, "ra\n");
	while (p2 > 0 && p2--)
		rotate(stack_b[0], stack_b[1], 0, "rb\n");
	while ((*stack_a[1])->number > target
			&& (*stack_a[1])->number < (*stack_a[0])->number)
		rotate(stack_a[0], stack_a[1], 1, "rra\n");
	push(stack_b[0], stack_a[0], "pa\n");
}

void	sort_stack(t_elem **a_top, t_elem **a_bottom,
		t_elem **b_top, t_elem **b_bottom)
{
	int		target;
	t_elem	**stack_a[2];
	t_elem	**stack_b[2];

	stack_a[0] = a_top;
	stack_a[1] = a_bottom;
	stack_b[0] = b_top;
	stack_b[1] = b_bottom;
	if (!is_sort(*a_top))
		rotate(stack_a[0], stack_a[1], 0, "ra\n");
	while (*b_top)
	{
		target = search_cheaper(*a_top, *b_top, 0);
		ssort(stack_a, stack_b, target);
	}
	while (!is_sort(*a_top))
	{
		if ((*a_top)->number > (*a_bottom)->number)
			rotate(a_top, a_bottom, 0, "ra\n");
		else
			rotate(a_top, a_bottom, 1, "rra\n");
	}
}
