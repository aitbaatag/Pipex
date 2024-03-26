/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:50 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/26 01:44:03 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(t_pipex *pipex)
{
	pipex->path1 = get_path(pipex->cmd1[0], pipex);
	if (pipex->path1 == NULL)
	{
		ft_putstr_fd("command not found: \n", 1);
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	execve(pipex->path1, pipex->cmd1, NULL);
	perror("execve failed in the first cmd");
	ft_error_free(pipex);
	exit(EXIT_FAILURE);
}

void	second_child_process(t_pipex *pipex)
{
	pipex->path2 = get_path(pipex->cmd2[0], pipex);
		if (pipex->path2 == NULL)
	{
		ft_putstr_fd("command not found: \n", 1);
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	execve(pipex->path2, pipex->cmd2, NULL);
	perror("execve failed in the second cmd");
	ft_error_free(pipex);
	exit(EXIT_FAILURE);
}

void	open_file(t_pipex *pipex, char **argv)
{
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->outfile < 0)
	{
		perror(ERR_OUTFILE);
		exit(EXIT_FAILURE);
	}
	pipex->infile = open(argv[1], O_RDONLY, 0666);
	if (pipex->infile < 0)
	{
		perror(ERR_INFILE);
		exit(EXIT_FAILURE);
	}
}

void	pipex_init(char **argv, char *envp[], t_pipex *pipex)
{
	p_init(pipex);
	open_file(pipex, argv);
	pipex->full_path = env_path(envp);
	pipex->split_path = ft_split(pipex->full_path, ':');
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (pipe(pipex->fd) < 0)
	{
		perror(ERR_PIPE);
		exit(EXIT_FAILURE);
	}
	// // pipex->path1 = get_path(pipex->cmd1[0], pipex);
	// if (pipex->path1 == NULL)
	// {
	// 	ft_putstr_fd("command not found: \n", 1);
	// 	ft_error_free(pipex);
	// 	exit(EXIT_FAILURE);
	// }
	// // pipex->path2 = get_path(pipex->cmd2[0], pipex);
	// if (pipex->path2 == NULL)
	// {
	// 	ft_putstr_fd("command not found: \n", 1);
	// 	ft_error_free(pipex);
	// 	exit(EXIT_FAILURE);
	// }
}
