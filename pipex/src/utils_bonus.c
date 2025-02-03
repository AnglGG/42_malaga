/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:08:07 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/03 17:13:15 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	input_arg_bonus(char **argv, int *fd)
{
	int		input_file;

	if (pipe(fd) == -1)
	{
		perror("Error creando la tubería");
		exit(EXIT_FAILURE);
	}
	input_file = open(argv[1], O_RDONLY);
	if (input_file == -1)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	dup2(input_file, STDIN_FILENO);
	close(input_file);
}

void	output_arg_bonus(char *argv)
{
	int		output_file;

	output_file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	dup2(output_file, STDOUT_FILENO);
	close(output_file);
}

void	child_process_1_bonus(int *fd, char *argv, char *output, char **envp, int last)
{
	char	*cmd[4];

	if (last)
	{
		output_arg_bonus(output);
	}
	else
	{
		dup2(fd[1], STDOUT_FILENO);
	}
	close (fd[0]);
	close (fd[1]);
	create_command(cmd, argv);
	execve("/bin/sh", cmd, envp);
	perror("Error ejecutando el comando");
	exit(-1);
}

void	parent_process_bonus(int pid_fork, int *fd)
{
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	waitpid(pid_fork, NULL, 0);
}
