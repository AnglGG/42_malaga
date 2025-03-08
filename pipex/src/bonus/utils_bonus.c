/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:12:44 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/07 20:24:27 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_arguments(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (ft_strlen(argv[1]) != 8)
		{
			ft_printf("Error: Argumento 'here_doc' mal formado\n");
			exit(EXIT_FAILURE);
		}
		if (argc < 6)
		{
			ft_printf("Faltan argumentos en here_doc\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (argc < 5)
		{
			ft_printf("Faltan argumentos\n");
			exit(EXIT_FAILURE);
		}
	}
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
	return (data);
}

int	get_cmd_start(int here_doc)
{
	if (here_doc)
		return (3);
	else
		return (2);
}

int	setup_input(t_pipex_data *data, char **argv)
{
	int	fd;
	int	pipe_fd[2];

	if (data->here_doc)
	{
		if (pipe(pipe_fd) == -1)
			error_exit(data, "pipe error");
		heredoc_input(argv[2], pipe_fd);
		close(pipe_fd[1]);
		return (pipe_fd[0]);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(data, "Error opening input file");
	return (fd);
}
