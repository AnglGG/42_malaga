/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:12:16 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/08 13:24:32 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **array)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

char	*find_variable_in_env(char **envp, const char *variable)
{
	size_t	len;
	int		i;
	char	*env_var;

	len = ft_strlen(variable);
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], variable, len) == 0)
		{
			env_var = ft_strdup(envp[i] + len);
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

char	*find_valid_path(char **cmd_path, char *total_cmd)
{
	char	*total_cmd_path;
	int		i;

	i = 0;
	total_cmd_path = NULL;
	while (cmd_path[i])
	{
		total_cmd_path = ft_strcat(cmd_path[i], total_cmd);
		if (!total_cmd_path)
			return (NULL);
		if (access(total_cmd_path, F_OK | X_OK) == 0)
		{
			return (total_cmd_path);
		}
		free(total_cmd_path);
		i ++;
	}
	return (NULL);
}

char	*handle_invalid_cmd_path(char **cmd_path, char *total_cmd)
{
	free_cmd_path(cmd_path, total_cmd);
	return (NULL);
}

void	free_cmd_path(char	**matrix,	char	*cmd)
{
	free_matrix(matrix);
	free (cmd);
}
