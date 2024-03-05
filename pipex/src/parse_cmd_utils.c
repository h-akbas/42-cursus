/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:55:23 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 20:46:49 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_parser(t_parser *parser, char *str, t_data *d)
{
	parser->i = 0;
	parser->buf = safe_alloc(ft_calloc(ft_strlen(str) + 1, sizeof(char)), CHECK,
			d);
	parser->buf_i = 0;
	parser->state = NORMAL;
	parser->tokens = NULL;
}

void	add_token_to_list(t_parser *parser, t_data *d)
{
	t_list	*new_token;
	char	*content;

	if (parser->buf_i != 0)
	{
		parser->buf[parser->buf_i] = '\0';
		content = safe_alloc(ft_strdup(parser->buf), TRACK, d);
		new_token = safe_alloc(ft_lstnew(content), TRACK, d);
		ft_lstadd_back(&(parser->tokens), new_token);
		parser->buf_i = 0;
	}
}

char	**convert_list_to_array(t_parser *parser, t_data *d)
{
	t_list	*current;
	char	**cmd_exe;
	int		i;

	cmd_exe = (char **)safe_alloc(ft_calloc(ft_lstsize(parser->tokens) + 1,
				sizeof(char *)), TRACK, d);
	i = 0;
	current = parser->tokens;
	while (current)
	{
		cmd_exe[i++] = (char *)current->content;
		current = current->next;
	}
	ft_lstclear(&parser->tokens, NULL);
	return (cmd_exe);
}
