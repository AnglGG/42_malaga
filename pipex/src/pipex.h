/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:27 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/05 12:22:21 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex_data
{
	int		fd[2];
	char	*output;
	char	**envp;
	int		here_doc;
}	t_pipex_data;

void	check_args(int argc, int *fd);
void	create_command(char **cmd, char *argv);
void	child_process_1(int *fd, char **argv, char **envp);
void	child_process_2(int *fd, char **argv, char **envp);
void	parent_process(int *pid_fork_2, int *fd, char **argv, char **envp);

void	check_args_bonus(int argc, int *fd);
void	child_process_1_bonus(t_pipex_data *data, char *cmd_str, int last);
void	parent_process_bonus(int pid_fork, int *fd);
void	heredoc_input(char *lim, int *fd);
void	input_arg_bonus(char **argv, int *fd, int here_doc);
void	create_command_bonus(char **cmd, char *argv);
#endif