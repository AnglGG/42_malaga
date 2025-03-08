/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 13:49:37 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid_fork;
	int	pid_fork_2;
	int	fd[2];

	pid_fork = -1;
	pid_fork_2 = -1;
	check_args(argc, fd);
	pid_fork = fork();
	if (pid_fork == -1)
	{
		perror("Error en el fork");
		exit(-1);
	}
	else if (pid_fork == 0)
	{
		child_process_1(fd, argv, envp);
	}
	else
	{
		parent_process(&pid_fork_2, fd, argv, envp);
	}
	waitpid(pid_fork, NULL, 0);
	waitpid(pid_fork_2, NULL, 0);
}
