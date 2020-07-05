
#include "push_swap.h"

int		execute_command(char *line, t_elem *stack_a[], t_elem *stack_b[])
{
	if (!ft_strcmp(line, "sa"))
		swap(&stack_a[0], "");
	else if (!ft_strcmp(line, "sb"))
		swap(&stack_b[0], "");
	else if (!ft_strcmp(line, "ss"))
		double_swap(&stack_a[0], &stack_b[0], "");
	else if (!ft_strcmp(line, "pa"))
		push(&stack_b[0], &stack_a[0], "");
	else if (!ft_strcmp(line, "pb"))
		push(&stack_a[0], &stack_b[0], "");
	else if (!ft_strcmp(line, "ra"))
		rotate(&stack_a[0], &stack_a[1], 0, "");
	else if (!ft_strcmp(line, "rb"))
		rotate(&stack_b[0], &stack_b[1], 0, "");
	else if (!ft_strcmp(line, "rr"))
		double_rotate(stack_a, stack_b, 0, "");
	else if (!ft_strcmp(line, "rra"))
		rotate(&stack_a[0], &stack_a[1], 1, "");
	else if (!ft_strcmp(line, "rrb"))
		rotate(&stack_b[0], &stack_b[1], 1, "");
	else if (!ft_strcmp(line, "rrr"))
		double_rotate(stack_a, stack_b, 1, "");
	else
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_elem	*stack_a[2];
	t_elem	*stack_b[2];
	char	*line;

	stack_a[0] = (t_elem *)malloc(sizeof(t_elem));
	stack_a[0]->number = 0;
	stack_a[1] = 0;
	stack_b[0] = 0;
	stack_b[1] = 0;
	if (fill_stack(argc, argv, &stack_a[0], &stack_a[1]))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "") ||
				execute_command(line, stack_a, stack_b))
			break ;
		if (is_sort(stack_a[0]) && !stack_b[0])
			ft_putstr("OK\n");
	}
	if (!is_sort(stack_a[0]) || stack_b[0])
		ft_putstr("KO\n");
	return (0);
}
