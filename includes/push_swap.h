#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_elem
{
	int				number;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

int					get_next_line(const int fd, char **line);
int					fill_stack(int argc, char **argv, t_elem **a_top,
					t_elem **a_bottom);
void				rotate(t_elem **stack_top, t_elem **stack_bottom,
					int reverse, char *command);
void				median_sort(t_elem **first_stack_top, t_elem
					**first_stack_bottom, t_elem **second_stack_top,
					t_elem **second_stack_bottom);
void				double_rotate(t_elem *stack_a[], t_elem *stack_b[],
					int reverse, char *command);
void				sort_stack(t_elem **first_stack_top,
					t_elem **first_stack_bottom,
					t_elem **second_stack_top, t_elem **second_stack_bottom);
void				push(t_elem **from, t_elem **to, char *command);
void				swap(t_elem **stack, char *command);
int					ft_is_number(char *str);
int					get_smaller(int first, int second);
int					stack_size(t_elem *stack);
int					is_sort(t_elem *first_stack_top);
void				print_stack(t_elem *stack, char title[]);
void				add_number(int number, t_elem **a_stack_top,
					t_elem **a_stack_bottom);
void				double_swap(t_elem **first_stack, t_elem **second_stack,
					char *command);
int					stack_size(t_elem *stack);

#endif
