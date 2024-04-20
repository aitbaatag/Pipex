/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:03 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/30 00:41:58 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_err(int i, char *err)
{
	if (i == 2)
	{
		ft_putstr_fd("Error: Bad argument\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 2);
		ft_putstr_fd("./pipex here_doc <LIMITER> <cmd> <cmd1> <...> <file>", 2);
		exit (EXIT_FAILURE);
	}
	if (i == 1)
	{
		perror (err);
		exit(EXIT_FAILURE);
	}
	if (i == 4)
		perror ("");
	else
	{
		perror("PATH variable not found.\n");
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
			free (str[i]);
			i++;
		}
		free (str);
		str = NULL;
	}
}

void	ft_error_free(t_pipex *pipex, int i)
{
	if (ft_strncmp(pipex->argv[1], "here_doc", 8) == 0
		&& ft_strlen (pipex->argv[1]) == 8 && i == 2)
		return ;
	if (pipex->path)
	{
		free (pipex->path);
		pipex->path = NULL;
	}
	if (pipex->cmd)
		free_it (pipex->cmd);
	if (i == 1)
		free_it(pipex->split_path);
	if (i == 0)
	{
		perror("error dup2\n");
		exit (EXIT_FAILURE);
	}
	if (i == -1)
	{
		free_it(pipex->split_path);
		exit(EXIT_FAILURE);
	}
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
