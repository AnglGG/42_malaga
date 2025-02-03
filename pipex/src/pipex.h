/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:53:27 by anggalle          #+#    #+#             */
/*   Updated: 2025/02/03 17:10:14 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	check_args(int argc, int *fd);
void	create_command(char **cmd, char *argv);
void	child_process_1(int *fd, char **argv, char **envp);
void	child_process_2(int *fd, char **argv, char **envp);
void	parent_process(int *pid_fork_2, int *fd, char **argv, char **envp);

void	check_args_bonus(int argc, int *fd);
void	child_process_1_bonus(int *fd, char **argv, char **envp);
void	child_process_2_bonus(int *fd, char **argv, char **envp);
void	parent_process_bonus(int *pid_fork_2, int *fd, char **argv, char **envp);

#endif