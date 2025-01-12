/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2025/01/12 14:22:14 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_args(int argc, int *fd)
{
	if (argc != 5)
	{
		write(STDERR_FILENO, "Error: Número de argumentos incorrecto\n", 39);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
    {
        perror("Error creando la tubería");
        exit(EXIT_FAILURE);
    }
}

void create_command(char **cmd, char *argv)
{
	cmd[0] = "/bin/sh";
	cmd[1] = "-c";
	cmd[2] = argv;
	cmd[3] = NULL;
}

void child_process_1(int *fd, char **argv, char **envp)
{
	int input_file = open(argv[1], O_RDONLY);
	char *cmd[4];

	if (input_file == -1)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	dup2(input_file, STDIN_FILENO);
	close(input_file);
	close (fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]);
	create_command(cmd, argv[2]);
	execve("/bin/sh", cmd, envp);
	perror("Error ejecutando el primer comando");
	exit(-1);
	
}

void child_process_2(int *fd, char **argv, char **envp)
{
	int output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *cmd[4];

	if (output_file == -1)
	{
		perror("Error al abrir el archivo de salida");
		exit(EXIT_FAILURE);
	}
	dup2(output_file, STDOUT_FILENO);
	close (output_file);
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	create_command(cmd, argv[3]);
	execve("/bin/sh", cmd, envp);
	perror("Error ejecutando el segundo comando");
	exit(-1);
	
}

void parent_process(int *pid_fork_2, int *fd, char **argv, char **envp)
{
	*pid_fork_2 = fork();
	if (*pid_fork_2 == -1)
	{
		perror("Error en el fork");
		exit(-1);
	}
	else if (*pid_fork_2 == 0) // Hijo
	{
		child_process_2(fd, argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
}

int main(int argc, char **argv, char **envp)
{
	int pid_fork;
	int pid_fork_2;
	int fd[2];

	check_args(argc, fd);
	pid_fork = fork();
	
	if (pid_fork == -1)
	{
		perror("Error en el fork");
		exit(-1);
	}
	else if (pid_fork == 0) //Proceso hijo
	{
		child_process_1(fd, argv, envp);
	}
	else //Proceso padre
	{
		parent_process(&pid_fork_2, fd, argv, envp);	
	}
	waitpid(pid_fork, NULL, 0);
	waitpid(pid_fork_2, NULL, 0);
	
}
