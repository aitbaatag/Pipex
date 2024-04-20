/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:50 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/30 00:58:22 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(t_pipex *pipex)
{
	pipex->path1 = get_path(pipex->cmd1[0], pipex);
	if (pipex->path1 == NULL)
	{
		ft_putstr_fd("command not found: \n", 2);
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
	{
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->fd[0]);
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
	{
		perror("error dup2\n");
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	execve(pipex->path1, pipex->cmd1, pipex->envp);
	perror("execve failed in the first cmd");
	ft_error_free(pipex);
	exit(EXIT_FAILURE);
}

void	second_child_process(t_pipex *pipex)
{
	pipex->path2 = get_path(pipex->cmd2[0], pipex);
	if (pipex->path2 == NULL)
	{
		ft_putstr_fd("command not found: \n", 2);
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
	{
		perror("error dup2\n");
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->fd[1]);
	if (dup2(pipex->fd[0], STDIN_FILENO) < 0)
	{
		perror("error dup2\n");
		ft_error_free(pipex);
		exit (EXIT_FAILURE);
	}
	execve(pipex->path2, pipex->cmd2, pipex->envp);
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
	}
}

void	pipex_init(char **argv, char *envp[], t_pipex *pipex)
{
	pipex->envp = envp;
	p_init(pipex);
	open_file(pipex, argv);
	pipex->full_path = env_path(envp);
	if (!pipex->full_path)
		pipex->split_path = NULL;
	else
		pipex->split_path = ft_split(pipex->full_path, ':');
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (pipe(pipex->fd) < 0)
	{
		perror(ERR_PIPE);
		ft_error_free(pipex);
		exit(EXIT_FAILURE);
	}
}
