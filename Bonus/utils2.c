/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:56:03 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/23 12:13:35 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*env_path(char **envp)
{
	int		i;
	char	*str_path;

	str_path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			str_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
	{
		perror("PATH variable not found.\n");
		exit(EXIT_FAILURE);
	}
	return (str_path);
}

void	p_init(t_pipex *pipex, char **argv, char **envp, int argc)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->full_path = env_path(envp);
	pipex->split_path = ft_split(pipex->full_path, ':');
}

void	exec_init(t_pipex *pipex, int i)
{
	if (ft_strncmp(pipex->argv[1], "here_doc", 8) == 0
		&& ft_strlen (pipex->argv[1]) == 8 && i == 2)
		return ;
	if (i <= pipex->argc - 2)
	{
		pipex->cmd = ft_split(pipex->argv[i], ' ');
		pipex->path = get_path(pipex->cmd[0], pipex);
	}
}
