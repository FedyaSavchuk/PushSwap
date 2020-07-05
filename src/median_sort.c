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

int		*make_array(t_elem **a_top)
{
	int		i;
	int		*array;
	t_elem	*start;

	start = *a_top;
	array = (int *)malloc(sizeof(int) * stack_size(*a_top));
	i = 0;
	while (*a_top)
	{
		array[i] = (*a_top)->number;
		(*a_top) = (*a_top)->prev;
		i++;
	}
	*a_top = start;
	return (array);
}

int		search_median(int *array, int n)
{
	int i;
	int j;
	int temp;
	int median;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	if (n % 2 == 0)
		median = (array[(n - 1) / 2] + array[n / 2]) / 2;
	else
		median = array[n / 2];
	return (median);
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
			rotate(a_top, a_bottom, 0, "ra\n");
		else
			push(a_top, b_top, "pb\n");
		i++;
	}
}

void	median_sort(t_elem **a_top, t_elem **a_bottom,
					t_elem **b_top, t_elem **b_bottom)
{
	int median;

	while (stack_size(*a_top) > 2)
	{
		median = search_median(make_array(a_top),
				stack_size(*a_top));
		sort(a_top, a_bottom, b_top, median);
	}
	*b_bottom = *b_top;
	while ((*b_bottom)->prev)
		*b_bottom = (*b_bottom)->prev;
}
