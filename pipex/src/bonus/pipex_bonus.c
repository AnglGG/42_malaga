/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:12:49 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/07 20:13:57 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	*data;
	int				nb_cmd;
	int				i;
	int				cmd_start;

	check_arguments(argc, argv);
	data = init_pipex_data();
	data->here_doc = is_here_doc(argv);
	data->envp = envp;
	data->output = argv[argc - 1];
	cmd_start = get_cmd_start(data->here_doc);
	data->input_fd = setup_input(data, argv);
	nb_cmd = argc - cmd_start - 1;
	i = 0;
	while (i < nb_cmd)
	{
		data->input_fd = execute_command(data, argv[cmd_start + i],
				(i == nb_cmd - 1));
		i++;
	}
	free(data);
	return (0);
}
