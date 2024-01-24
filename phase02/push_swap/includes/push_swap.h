//ADD HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

enum    e_loc
{
    A_TOP,
    A_BOTTOM,
    B_TOP,
    B_BOTTOM,
};

typedef struct s_set
{
    enum e_loc  loc;
    int         size;
}               t_set;

typedef struct s_split_destinations
{
    t_set   min;
    t_set   mid;
    t_set   max;
}           t_dest;

int         main(int argc, char **argv);
void        sort(t_data *data);
void        sort_three(t_data *data);
void        sort_five(t_data *data);

void        sort(t_data *data);
void        recursive_sort(t_data *data);
void        sort_two(t_data *data);
void        sort_three(t_data *data);
void        get_set_current_value(t_data *data, t_set *set, int n);
void        get_set_max_value(t_data *data, t_set *set);
t_stack     *locate_stack(t_data *data, enum e_loc loc);
//to be continued




#endif
