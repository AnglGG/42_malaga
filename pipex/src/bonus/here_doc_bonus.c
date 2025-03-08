/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:26:43 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/07 19:58:19 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_here_doc(char **argv)
{
	return (ft_strncmp(argv[1], "here_doc", 8) == 0);
}

void	heredoc_input(char *limiter, int *pipe_fd)
{
	char	*line;
	size_t	len;

	len = 0;
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (strncmp(line, limiter, strlen(limiter)) == 0
			&& line[strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		len = strlen(line);
		write(pipe_fd[1], line, len);
		free(line);
	}
}
