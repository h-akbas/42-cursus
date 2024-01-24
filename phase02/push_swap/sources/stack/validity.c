/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:17:41 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 19:26:22 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	check_sorted(t_data *data)
{
	int	i;
	int rank;
	
	i = data->a->top;
	rank = 1;
	while (rank <= data->a->size)
	{
		if (data->a->arr[i] != rank)
			return (false);
		rank++;
		i = get_lower(i, data->a->size);
	}
	return (true);
}

void	check_duplicate(t_data *data, int *)