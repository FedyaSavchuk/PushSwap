/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   push_swap.c                                        :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: fedyasavchuk <fedyasavchuk@student.42.fr>  +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2020/06/10 17:10:43 by fedyasavchuk      #+#    #+#             *//*   Updated: 2020/06/10 17:10:43 by fedyasavchuk     ###   ########.fr       *//*                                                                            *//* ************************************************************************** */#include "push_swap.h"int		main(int argc, char **argv){    t_elem *a_stack_top;    t_elem *a_stack_bottom;    t_elem *b_stack_top;    t_elem *b_stack_bottom;    a_stack_top = 0;    a_stack_bottom = 0;    b_stack_top = 0;    b_stack_bottom = 0;    a_stack_top = (t_elem *)malloc(sizeof(t_elem));   	a_stack_top->number = 0;    a_stack_bottom = a_stack_top;    fill_stack(argc, argv, &a_stack_top, &a_stack_bottom);    median_sort(&a_stack_top, &a_stack_bottom, &b_stack_top, &b_stack_bottom);    sort_stack(&a_stack_top, &a_stack_bottom, &b_stack_top, &b_stack_bottom);    return (0);}