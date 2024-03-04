/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:15:12 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:59:27 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include "../lib/libft/libft.h"

# define MEM_ERROR "Memory allocation failed"

typedef struct s_data
{
	char		**env;
	char		**env_paths;
	char		*input_file;
	bool		here_doc;
	char		*limiter;
	char		*output_file;
	int			n_cmd;
	char		***commands;
	int			last_cmd_exit_status;

	t_list		*allocated_pointers;
}				t_data;

typedef enum t_alloc
{
	CHECK,
	TRACK
}				t_alloc;

# define READ_END 0
# define WRITE_END 1

// Parser structure
typedef enum t_prs_state
{
	NORMAL,
	IN_SINGLE_QUOTE,
	IN_DOUBLE_QUOTE
}				t_prs_state;

typedef struct s_parser
{
	t_prs_state	state;
	int			i;
	char		*buf;
	int			buf_i;
	t_list		*tokens;
}				t_parser;

void			init_data(t_data *d, int argc, char **argv, char **env);
char			**parse_cmd(char *str, t_data *d);
void			init_parser(t_parser *parser, char *str, t_data *d);
void			add_token_to_list(t_parser *parser, t_data *d);
char			**convert_list_to_array(t_parser *parser, t_data *d);
void			execute_pipeline(t_data *d);
void			setup_input(char *filename, char *limiter, t_data *d);
void			setup_output(char *filename, t_data *d);
char			*get_bin_path(char *bin, char **env_path, t_data *d);
void			put_error(const char *context, char *description,
					int exit_status, t_data *d);
void			put_sys_error(const char *context, int errnum, t_data *d);
ssize_t			safe_write_fd(const void *buf, int fd, t_data *d);
void			*s_alloc(void *pointer, t_alloc mode, t_data *d);
void			track_alloc(t_data *d, void *pointer);
int				safe_open(const char *pathname, int flags, mode_t mode,
					t_data *d);
int				safe_close(int fd, t_data *d);
int				safe_dup2(int oldfd, int newfd, t_data *d);
int				safe_unlink(const char *pathname, t_data *d);
int				safe_execve(const char *pathname, char *const argv[],
					char *const envp[], t_data *d);
pid_t			safe_fork(t_data *d);
int				safe_pipe(int pipefd[2], t_data *d);
pid_t			safe_wait(int *wstatus, t_data *d);

#endif
