/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/03 17:14:27 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int pid_fork;
	int i;
	int fd[2];
	int last;

	input_arg_bonus(argv, fd);
	i = 2;
	last = 0;
	while (i < argc - 1)
	{
		if (i == (argc - 2))
			last = 1;
		pid_fork = fork();
		if (pid_fork == -1)
		{
			perror("Error en el fork");
			exit(-1);
		}
		else if (pid_fork == 0)
			child_process_1_bonus(fd, argv[i], argv[argc - 1], envp, last);
		else
			parent_process_bonus(pid_fork, fd);
		i ++;
	}
}
