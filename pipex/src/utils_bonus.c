/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:08:07 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/05 12:22:42 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_arg_bonus(char **argv, int *fd, int here_doc)
{
	int	input_file;

	input_file = 0;
	if (here_doc)
		heredoc_input(argv[2], fd);
	else
	{
		input_file = open(argv[1], O_RDONLY);
		if (input_file < 0)
		{
			perror("open input_file file");
			exit(EXIT_FAILURE);
		}
		dup2(input_file, STDIN_FILENO);
		close(input_file);
		if (pipe(fd) == -1)
		{
			perror("pipe error");
			exit(EXIT_FAILURE);
		}
	}
}

void	output_arg_bonus(char *argv, int here_doc)
{
	int		output_file;

	if (here_doc)
		output_file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output_file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	dup2(output_file, STDOUT_FILENO);
	close(output_file);
}

void	child_process_1_bonus(t_pipex_data *data, char *cmd_str, int last)
{
	char	*cmd[4];

	if (last)
		output_arg_bonus(data->output, data->here_doc);
	else
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	create_command_bonus(cmd, cmd_str);
	execve("/bin/sh", cmd, data->envp);
	perror("Error ejecutando el comando");
	exit(EXIT_FAILURE);
}

void	parent_process_bonus(int pid_fork, int *fd)
{
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	waitpid(pid_fork, NULL, 0);
}

void	create_command_bonus(char **cmd, char *argv)
{
	cmd[0] = "/bin/sh";
	cmd[1] = "-c";
	cmd[2] = argv;
	cmd[3] = NULL;
}