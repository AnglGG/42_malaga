/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2025/01/18 20:22:44 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

void	input_arg(char **argv, int *fd)
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
void	output_arg(char *argv)
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

void	create_command(char **cmd, char *argv)
{
	cmd[0] = "/bin/sh";
	cmd[1] = "-c";
	cmd[2] = argv;
	cmd[3] = NULL;
}

void	child_process_1(int *fd, char *argv, char *output, char **envp, int last)
{
	char	*cmd[4];

	if (last)
	{
		output_arg(output);
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

void	parent_process(int pid_fork, int *fd)
{
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	waitpid(pid_fork, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int pid_fork;
	int i;
	int fd[2];
	int last;

	input_arg(argv, fd);
	i = 2;
	last = 0;
	while (i < argc - 1)
	{
		if (pipe(fd) == -1)
		{
			perror("Error creando la tubería");
			exit(EXIT_FAILURE);
		}
		if (i == (argc - 2))
			last = 1;
		pid_fork = fork();
		if (pid_fork == -1)
		{
			perror("Error en el fork");
			exit(-1);
		}
		else if (pid_fork == 0)
			child_process_1(fd, argv[i], argv[argc - 1], envp, last);
		else
			parent_process(pid_fork, fd);
		i ++;
	}
}
