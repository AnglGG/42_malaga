/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:27 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 13:43:04 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	check_args(int argc, int *fd);
char	*create_command(char *cmd, char **envp, char **complete_command);
void	child_process_1(int *fd, char **argv, char **envp);
void	child_process_2(int *fd, char **argv, char **envp);
void	parent_process(int *pid_fork_2, int *fd, char **argv, char **envp);
char	*find_variable_in_env(char **envp, const char *variable);
char	*find_valid_path(char **cmd_path, char *total_cmd);
char	*handle_invalid_cmd_path(char **cmd_path, char *total_cmd);
void	free_cmd_path(char **matrix, char *cmd);
void	free_matrix(char **array);

#endif