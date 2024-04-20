/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:48 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/30 00:55:31 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_init(t_pipex *pipex)
{
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->full_path = NULL;
	pipex->split_path = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

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
		return (NULL);
	}
	return (str_path);
}

void	p_pipex(int i, t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		perror("fork fail");
		ft_error_free(pipex);
		exit (EXIT_FAILURE);
	}
	else if (pipex->pid == 0)
	{
		if (i == 0)
			first_child_process(pipex);
		else if (i == 1)
			second_child_process(pipex);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 0;
	if (argc == 5)
	{
		pipex_init(argv, envp, &pipex);
		while (i < 2)
			p_pipex(i++, &pipex);
		close(pipex.fd[1]);
		close(pipex.fd[0]);
		while (wait(NULL) != -1)
			;
		ft_error_free(&pipex);
	}
	else
	{
		ft_putstr_fd("Error: Bad argument\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		return (1);
	}
	return (0);
}
