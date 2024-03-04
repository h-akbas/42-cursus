/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:29:14 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/02 23:17:11 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last;

	if (!new_lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_lst;
}
