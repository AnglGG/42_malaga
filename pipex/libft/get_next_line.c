/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:14:38 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/09 19:43:03 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_find_char(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*read_and_append(int fd, char *remaining, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remaining);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remaining)
			remaining = ft_strdup("");
		temp = remaining;
		remaining = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_find_char(buffer, '\n'))
			break ;
	}
	return (remaining);
}

static char	*extract_line(char	*line)
{
	char	*remaining;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i ++;
	if (line[i] == '\0')
		return (NULL);
	remaining = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remaining == '\0')
	{
		free(remaining);
		remaining = NULL;
	}
	line[i + 1] = '\0';
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*remaining_content;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = read_and_append(fd, remaining_content, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	remaining_content = extract_line(line);
	return (line);
}
