/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:26:45 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 14:23:30 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*create_command(char *cmd, char **envp, char **complete_command)
{
	char	*env_path;
	char	**cmd_path;
	char	*total_cmd;
	char	*valid_path;

	if (!cmd)
		return (NULL);
	env_path = find_variable_in_env(envp, "PATH=");
	if (!env_path)
		return (NULL);
	cmd_path = ft_split(env_path, ':');
	free(env_path);
	if (!cmd_path)
		return (NULL);
	total_cmd = ft_strcat("/", complete_command[0]);
	if (!total_cmd)
		return (handle_invalid_cmd_path(cmd_path, total_cmd));
	valid_path = find_valid_path(cmd_path, total_cmd);
	if (!valid_path)
		return (handle_invalid_cmd_path(cmd_path, total_cmd));
	free_cmd_path(cmd_path, total_cmd);
	return (valid_path);
}

void	exec_command(char *cmd_str, char **envp)
{
	char	*path;
	char	**complete_command;

	complete_command = ft_split(cmd_str, ' ');
	path = create_command(cmd_str, envp, complete_command);
	if (path)
	{
		execve(path, complete_command, envp);
		perror("Error ejecutando comando");
		exit(EXIT_FAILURE);
	}
	write(2, "Comando incorrecto\n", 19);
	free_matrix(complete_command);
	exit(-1);
}

void	output_arg(char *file, int here_doc)
{
	int	fd;

	if (here_doc)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error al abrir archivo de salida");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	child_process(t_pipex_data *data, char *cmd_str,
		int *pipe_fd, int is_last)
{
	if (dup2(data->input_fd, STDIN_FILENO) == -1)
	{
		error_exit(data, "dup2 error");
	}
	if (!is_last)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		{
			error_exit(data, "dup2 error");
		}
	}
	else
		output_arg(data->output, data->here_doc);
	close(data->input_fd);
	if (!is_last)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	exec_command(cmd_str, data->envp);
}

int	execute_command(t_pipex_data *data, char *cmd_str,
		int is_last)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (!is_last && pipe(pipe_fd) == -1)
		error_exit(data, "pipe error");
	pid = fork();
	if (pid < 0)
		error_exit(data, "fork error");
	if (pid == 0)
		child_process(data, cmd_str, pipe_fd, is_last);
	else
	{
		waitpid(pid, NULL, 0);
		close(data->input_fd);
		if (!is_last)
		{
			close(pipe_fd[1]);
			return (pipe_fd[0]);
		}
	}
	return (-1);
}
