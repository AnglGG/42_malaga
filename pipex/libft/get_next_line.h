/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:16:15 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/09 17:39:59 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                            GET_NEXT_LINE.H                               */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strdup(char *s1);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

#endif
