/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:56:58 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/29 16:10:48 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_pipex *pipex, int *fd)
{
	close (fd[0]);
	if (pipex->path == NULL)
	{
		ft_putstr_fd("command not found: \n", 2);
		ft_error_free(pipex, 1);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		ft_error_free(pipex, 0);
	execve (pipex->path, pipex->cmd, pipex->envp);
	perror("execve failed \n");
	ft_error_free(pipex, 1);
	exit(EXIT_FAILURE);
}

void	first_child_process(t_pipex *pipex, int *fd)
{
	if (ft_strncmp(pipex->argv[1], "here_doc", 8) == 0
		&& ft_strlen (pipex->argv[1]) == 8)
	{
		pipex->infile = open(".here", O_RDONLY);
		if (pipex->infile < 0)
		{
			exit_err(1, "error here_doc\n");
			unlink(".here");
		}
	}
	if (pipex->path == NULL)
	{
		ft_putstr_fd("command not found: \n", 2);
		ft_error_free(pipex, 1);
		exit(EXIT_FAILURE);
	}
	if (dup2 (pipex->infile, STDIN_FILENO) < 0)
		ft_error_free(pipex, -1);
	close (fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		ft_error_free(pipex, 0);
	execve (pipex->path, pipex->cmd, pipex->envp);
	perror("execve failed \n");
	ft_error_free(pipex, 1);
	exit(EXIT_FAILURE);
}

void	last_child_process(t_pipex *pipex)
{
	if (pipex->path == NULL)
	{
		ft_putstr_fd("command not found: \n", 2);
		ft_error_free(pipex, 1);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
		ft_error_free(pipex, 0);
	execve (pipex->path, pipex->cmd, pipex->envp);
	perror("execve failed \n");
	ft_error_free(pipex, 1);
	exit(EXIT_FAILURE);
}

void	ft_here_doc(char *limiter, t_pipex *pipex)
{
	free_it (pipex->split_path);
	pipex->ffd = open(".here", O_CREAT | O_WRONLY | O_RDONLY
			| O_TRUNC, 0666);
	if (pipex->ffd < 0)
		exit_err(1, "error here_doc\n");
	write(1, "heredoc> ", 9);
	pipex->line = get_next_line(0);
	while (pipex->line != NULL)
	{
		if ((ft_strncmp(pipex->line, limiter, ft_strlen(limiter)) == 0)
			&& (ft_strlen(pipex->line) - 1 == ft_strlen(limiter)))
		{
			free (pipex->line);
			break ;
		}
		write(1, "heredoc> ", 9);
		write(pipex->ffd, pipex->line, ft_strlen(pipex->line));
		free (pipex->line);
		pipex->line = NULL;
		pipex->line = get_next_line(0);
	}
	close (pipex->ffd);
	exit (EXIT_SUCCESS);
}

void	open_file(t_pipex *pipex, char **argv, int argc)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0
		&& ft_strlen(argv[1]) == 8)
	{
		if (argc <= 5)
			exit_err(2, NULL);
		pipex->outfile = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_APPEND, 0666);
		if (pipex->outfile < 0)
			exit_err(1, ERR_OUTFILE);
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY, 0666);
		if (pipex->infile < 0)
			perror(ERR_INFILE);
		pipex->outfile = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_TRUNC, 0666);
		if (pipex->outfile < 0)
			exit_err(1, ERR_OUTFILE);
	}
}
