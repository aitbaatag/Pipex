/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:53 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/30 01:17:13 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_err(int i, t_pipex *pipex)
{
	free_it(pipex->command);
	if (i == 1)
	{
		perror("");
		if (pipex->path1)
		{
			free(pipex->path1);
			pipex->path1 = NULL;
		}
		if (pipex->path2)
		{
			free(pipex->path2);
			pipex->path2 = NULL;
		}
		exit (EXIT_FAILURE);
	}
}

void	free_it(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	ft_error_free(t_pipex *pipex)
{
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->path2)
		free(pipex->path2);
	if (pipex->split_path)
		free_it(pipex->split_path);
	if (pipex->cmd1)
		free_it(pipex->cmd1);
	if (pipex->cmd2)
		free_it(pipex->cmd2);
}

char	*check_path(char *path, char *command)
{
	char	*valid_command;

	valid_command = ft_strjoin(path, command);
	if (access(valid_command, X_OK) == 0)
		return (valid_command);
	else
		return (free(valid_command), NULL);
}

char	*get_path(char *command, t_pipex *pipex)
{
	int		i;

	i = 0;
	if (command == NULL)
		return (NULL);
	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	if ((command[0] == '/' || command[0] == '.'))
		return (NULL);
	if (pipex->split_path)
	{
		while (pipex->split_path[i] != NULL)
		{
			pipex->curpath = ft_strjoin(pipex->split_path[i], "/");
			pipex->valid_path = check_path(pipex->curpath, command);
			free (pipex->curpath);
			if (pipex->valid_path != NULL)
				return (pipex->valid_path);
			free (pipex->valid_path);
			i++;
		}
	}
	return (NULL);
}
