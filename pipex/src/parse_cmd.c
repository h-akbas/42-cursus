/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:54:47 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:41:43 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>

static void	normal_state(char *str, t_parser *parser, t_data *d);
static void	single_quote_state(char *str, t_parser *parser);
static void	double_quote_state(char *str, t_parser *parser);

char	**parse_cmd(char *str, t_data *d)
{
	t_parser	parser;
	char		**cmd_exe;

	init_parser(&parser, str, d);
	while (str[parser.i])
	{
		if (parser.state == NORMAL)
			normal_state(str, &parser, d);
		else if (parser.state == IN_SINGLE_QUOTE)
			single_quote_state(str, &parser);
		else if (parser.state == IN_DOUBLE_QUOTE)
			double_quote_state(str, &parser);
		parser.i++;
	}
	if (parser.state != NORMAL)
		put_error("parse error", "unclosed quote", EXIT_FAILURE, d);
	add_token_to_list(&parser, d);
	cmd_exe = convert_list_to_array(&parser, d);
	free(parser.buf);
	return (cmd_exe);
}

static void	normal_state(char *str, t_parser *parser, t_data *d)
{
	if (str[parser->i] == ' ')
		add_token_to_list(parser, d);
	else if (str[parser->i] == '\"')
		parser->state = IN_DOUBLE_QUOTE;
	else if (str[parser->i] == '\'')
		parser->state = IN_SINGLE_QUOTE;
	else if (str[parser->i] == '\\')
		parser->buf[parser->buf_i++] = str[++parser->i];
	else
		parser->buf[parser->buf_i++] = str[parser->i];
}

static void	single_quote_state(char *str, t_parser *parser)
{
	if (str[parser->i] == '\'')
		parser->state = NORMAL;
	else
		parser->buf[parser->buf_i++] = str[parser->i];
}

static void	double_quote_state(char *str, t_parser *parser)
{
	if (str[parser->i] == '\"')
		parser->state = NORMAL;
	else if (str[parser->i] == '\\')
	{
		parser->i++;
		if (str[parser->i] == 'n')
			parser->buf[parser->buf_i++] = '\n';
		else if (str[parser->i] == 't')
			parser->buf[parser->buf_i++] = '\t';
		else if (str[parser->i] == '\"' || str[parser->i] == '\\')
			parser->buf[parser->buf_i++] = str[parser->i];
	}
	else
		parser->buf[parser->buf_i++] = str[parser->i];
}
