/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:14:38 by anggalle          #+#    #+#             */
/*   Updated: 2024/07/18 12:53:48 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	if (fd < 0)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	
}

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	int		reader;
	char	*tmp;

	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (reader == 0)
			break;
		buffer[reader] = 0;
		if (!left_c)
			ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}
