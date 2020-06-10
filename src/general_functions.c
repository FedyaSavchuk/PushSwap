/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:10:12 by fedyasavchuk      #+#    #+#             */
/*   Updated: 2020/06/10 17:10:12 by fedyasavchuk     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_size(t_elem *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		stack = stack->prev;
		size++;
	}
	return (size);
}

int		get_smaller(int first, int second)
{
	return (first < second ? first : second);
}

int		ft_is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		is_sort(t_elem *first_stack_top)
{
	while (first_stack_top->prev)
	{
		if (first_stack_top->number > first_stack_top->prev->number)
			return (0);
		first_stack_top = first_stack_top->prev;
	}
	return (1);
}

t_elem	*get_stack_bottom(t_elem *stack_top)
{
	while (stack_top->prev)
		stack_top = stack_top->prev;
	return (stack_top);
}
