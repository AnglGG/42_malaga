/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:37:19 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 14:24:34 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int argc, int *fd)
{
	if (argc != 5)
	{
		ft_printf("Error: Número de argumentos incorrecto\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creando la tubería");
		exit(EXIT_FAILURE);
	}
}

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

void	child_process_1(int *fd, char **argv, char **envp)
{
	int		input_file;
	char	*path;
	char	**complete_command;

	input_file = open(argv[1], O_RDONLY);
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
	complete_command = ft_split(argv[2], ' ');
	path = create_command(argv[2], envp, complete_command);
	if (path)
	{
		execve(path, complete_command, envp);
		perror("Error ejecutando el primer comando");
		exit(-1);
	}
	write(2, "Comando incorrecto\n", 19);
	free_matrix(complete_command);
}

void	child_process_2(int *fd, char **argv, char **envp)
{
	int		output_file;
	char	*path;
	char	**complete_command;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	complete_command = ft_split(argv[3], ' ');
	path = create_command(argv[3], envp, complete_command);
	if (path)
	{
		execve(path, complete_command, envp);
		perror("Error ejecutando el segundo comando");
		exit(-1);
	}
	free_matrix(complete_command);
}

void	parent_process(int *pid_fork_2, int *fd, char **argv, char **envp)
{
	*pid_fork_2 = fork();
	if (*pid_fork_2 == -1)
	{
		perror("Error en el fork");
		exit(-1);
	}
	else if (*pid_fork_2 == 0)
	{
		child_process_2(fd, argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
}
