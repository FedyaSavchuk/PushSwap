#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct      s_elem
{
    int             number;
    struct s_elem   *next;
}                   t_elem;

#endif