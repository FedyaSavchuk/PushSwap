/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:10:43 by fedyasavchuk      #+#    #+#             */
/*   Updated: 2020/06/10 17:10:43 by fedyasavchuk     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	add_number(int number, t_elem **a_stack_top, t_elem **a_stack_bottom)
{
	t_elem	*prev_elem;

	if (!((*a_stack_top)->number))
	{
		(*a_stack_top)->number = number;
		(*a_stack_top)->next = NULL;
		(*a_stack_top)->prev = NULL;
		*a_stack_top = *a_stack_bottom;
	}
	else
	{
		while (*a_stack_top)
		{
			prev_elem = *a_stack_top;
			*a_stack_top = (*a_stack_top)->next;
		}
		*a_stack_top = ft_memalloc(sizeof(t_elem));
		(*a_stack_top)->number = number;
		prev_elem->next = *a_stack_top;
		(*a_stack_top)->prev = prev_elem;
	}
}

void	fill_stack(int argc, char **argv, t_elem **a_top, t_elem **a_bottom)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
		{
			ft_printf("ERROR");
			return ;
		}
		add_number(ft_atoi(argv[i]), a_top, a_bottom);
		i++;
	}
}

void	print_stack(t_elem *stack, char title[])
{
	write(1, title, ft_strlen(title));
	write(1, "\n", 1);
	while (stack)
	{
		ft_putnbr(stack->number);
		ft_putchar('\n');
		stack = stack->prev;
	}
}

int		main(int argc, char **argv)
{
	t_elem *a_stack_top;
	t_elem *a_stack_bottom;
	t_elem *b_stack_top;
	t_elem *b_stack_bottom;

	a_stack_top = (t_elem *)malloc(sizeof(t_elem));
	a_stack_bottom = a_stack_top;
	fill_stack(argc, argv, &a_stack_top, &a_stack_bottom);
	median_sort(&a_stack_top, &a_stack_bottom, &b_stack_top, &b_stack_bottom);
	sort_stack(&a_stack_top, &a_stack_bottom, &b_stack_top, &b_stack_bottom);
	return (0);
}
