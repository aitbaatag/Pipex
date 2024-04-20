/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:56:41 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/29 14:04:10 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_pipe(t_pipex *pipex)
{
	int	err;

	err = pipe(pipex->fd);
	if (err < 0)
	{
		ft_putstr_fd(ERR_PIPE, 2);
		exit(EXIT_FAILURE);
	}
}

int	check(char *command)
{
	int		i;

	i = 0;
	if (!command)
		return (0);
	while (command[i] == ' ' && command[i])
		i++;
	if (command[i] == '\0')
		return (0);
	return (1);
}

void	ft_parent(t_pipex *pipex, int i)
{
	if (ft_strncmp(pipex->argv[1], "here_doc", 8) == 0
		&& ft_strlen (pipex->argv[1]) == 8 && i == 2)
		wait (NULL);
	close (pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	ft_error_free(pipex, i);
}

void	p_pipex(char *argv[], t_pipex *pipex, int i)
{
	p_pipe(pipex);
	exec_init(pipex, i);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if ((ft_strncmp(argv[1], "here_doc", 8) == 0
				&& ft_strlen (argv[1]) == 8) && (i == 2 || i == 3))
		{
			if (ft_strncmp(argv[1], "here_doc", 8) == 0 && i == 2)
				ft_here_doc(argv[2], pipex);
			else if (i == 3)
				first_child_process(pipex, pipex->fd);
		}
		else if (i == 2)
			first_child_process(pipex, pipex->fd);
		else if (i == pipex->argc - 2)
			last_child_process(pipex);
		else
			execute_command(pipex, pipex->fd);
	}
	else
		ft_parent(pipex, i);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 2;
	if (argc >= 5)
	{
		open_file(&pipex, argv, argc);
		p_init(&pipex, argv, envp, argc);
		while (i <= argc - 2)
			p_pipex(argv, &pipex, i++);
		i = 0;
		free_it (pipex.split_path);
		while (wait (NULL) != -1)
			;
		if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		{
			close(pipex.infile);
		}
		close(pipex.outfile);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			unlink(".here");
	}
	else
		exit_err(2, NULL);
	return (0);
}
