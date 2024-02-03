/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:19:05 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:32:59 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include "../../libraries/ft_printf/ft_printf.h"

void		record_instruction(t_data *data, enum e_ops instruction)
{
    t_list	*new;
    
    new = ft_lstnew(&instruction);
    if (!new)
        put_error(data);
    ft_lstadd_back(&data->instructions, new);
}

static const char	*verbalize_instruction(enum e_ops op)
{
    static const char	*string[12];
    
    string[0] = "null_op";
    string[1] = "pa";
    string[2] = "pb";
    string[3] = "ra";
    string[4] = "rb";
    string[5] = "rr";
    string[6] = "rra";
    string[7] = "rrb";
    string[8] = "rrr";
    string[9] = "sa";
    string[10] = "sb";
    string[11] = "ss";
    return (string[op]);
    
}
enum e_ops	map_instructions(t_list *instruction_list)
{
    return (*(enum e_ops *)instruction_list->content);
}

void		report_instructions(t_list *head)
{
    t_list	*current;
    
    current = head;
    while (current)
    {
        ft_printf("%s\n", verbalize_instruction(map_instructions(current)));
        current = current->next;
    }
}