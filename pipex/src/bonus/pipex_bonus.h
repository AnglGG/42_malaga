/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:12:47 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 14:42:47 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex_data
{
	int		here_doc;
	char	**envp;
	char	*output;
	int		input_fd;
}	t_pipex_data;

//EXECUTION
char			*create_command(char *cmd, char **envp,
					char **complete_command);
int				execute_command(t_pipex_data *data, char *cmd_str,
					int is_last);
void			child_process(t_pipex_data *data, char *cmd_str,
					int *pipe_fd, int is_last);
void			exec_command(char *cmd_str, char **envp);
void			output_arg(char *file, int here_doc);

//HERE_DOC
int				is_here_doc(char **argv);
void			heredoc_input(char *limiter, int *pipe_fd);

//UTILS
void			check_arguments(int argc, char **argv);
t_pipex_data	*init_pipex_data(void);
int				get_cmd_start(int here_doc);
int				setup_input(t_pipex_data *data, char **argv);

//ERROR
void			error_exit(t_pipex_data *data, const char *msg);

//PARSE
char			*find_variable_in_env(char **envp, const char *variable);
char			*find_valid_path(char **cmd_path, char *total_cmd);
char			*handle_invalid_cmd_path(char **cmd_path, char *total_cmd);
void			free_cmd_path(char **matrix, char *cmd);
void			free_matrix(char **array);

#endif