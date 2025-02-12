/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:32:37 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/05 12:21:00 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (c[i] != '\0')
	{
		len ++;
		i ++;
	}
	return (len);
}

static void	heredoc_loop(char *lim, int write_fd)
{
	char	*line;

	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, lim, ft_strlen(lim))
			&& line[ft_strlen(lim)] == '\n')
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
	}
}

void	heredoc_input(char *lim, int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		heredoc_loop(lim, fd[1]);
		close(fd[1]);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}
