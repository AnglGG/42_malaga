/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/05 12:31:52 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_arguments(int argc, char **argv)
{
	if ((ft_strncmp(argv[1], "here_doc ", 9) == 0 && argc < 6)
		|| (ft_strncmp(argv[1], "here_doc ", 9) != 0 && argc < 5))
	{
		perror("Argumentos mal introducidos");
		exit(EXIT_FAILURE);
	}
}

static int	is_here_doc(char **argv)
{
	return (ft_strncmp(argv[1], "here_doc", 8) == 0);
}

static int	get_cmd_start(int here_doc)
{
	if (here_doc)
		return (3);
	else
		return (2);
}

static int	create_process(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
t_pipex_data	*init_pipex_data(void)
{
	t_pipex_data	*data;

	data = malloc(sizeof(t_pipex_data));
	if (!data)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	data->here_doc = 0;
	data->envp = NULL;
	data->output = NULL;
	data->fd[0] = -1;
	data->fd[1] = -1;
	return (data);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	*data;
	int				pid_fork;
	int				last;
	int				cmd_start;

	check_arguments(argc, argv);
	data = init_pipex_data();
	data->here_doc = is_here_doc(argv);
	data->envp = envp;
	data->output = argv[argc - 1];
	input_arg_bonus(argv, data->fd, data->here_doc);
	cmd_start = get_cmd_start(data->here_doc);
	last = 0;
	while (cmd_start < argc - 1)
	{
		if (cmd_start == argc - 2)
			last = 1;
		pid_fork = create_process();
		if (pid_fork == 0)
			child_process_1_bonus(data, argv[cmd_start], last);
		else
			parent_process_bonus(pid_fork, data->fd);
		cmd_start++;
	}
	return (0);
}
