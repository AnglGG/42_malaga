/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:31 by anggalle          #+#    #+#             */
/*   Updated: 2024/12/22 23:37:02 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
//#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void modify_args(int argc, char **argv)
{
	int fd[2];

	if (argc != 5)
	{
		printf("Error en la introducción de comandos\n");
		exit(-1);
	}
	fd[0] = open(argv[1], O_RDONLY);
	if (!fd[0])
	{
		printf("Error al abrir el archivo de entrada");
		exit(-1);
	}
	dup2(fd[0], STDIN_FILENO);
	fd[1] = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	if (!fd[1])
	{
		printf("Error al abrir el archivo de salida");
		exit(-1);
	}
	dup2(fd[1], STDOUT_FILENO);
}

int main(int argc, char **argv)
{
	char *args[128];
	int pid_fork;

	modify_args(argc, argv);
	
	pid_fork = fork();

	if (pid_fork == 0) //Proceso hijo
	{
		execv(argv[], argv[1]);
		exit(-1);
	}
	else if (pid_fork > 0) //Proceso padre
	{
		
	}
	else
	{
		printf("Error en el fork");
		exit(-1);
	}
	
}
