/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:58:20 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/23 11:41:33 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* write, close, pipe, access, read, dup, dup2, execve, fork */
/* pid_t datatype it is defined in <sys/types.h> */
# include <sys/types.h>
# include <unistd.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror, perror */
# include <stdio.h>

/* libft functions */
# include "../libft/libft.h"

# define ERR_INFILE "ERROR infile"
# define ERR_OUTFILE "ERROR outfile"
# define ERR_INPUT "ERROR number of arguments invalid\n"
# define ERR_PIPE "ERROR pipe"
# define ERR_1CMD "ERROR first command invalid\n"
# define ERR_2CMD "ERROR second command invalid\n"

typedef struct s_pipex
{
	int		fd[2];
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	char	**command;
	int		infile;
	int		outfile;
	pid_t	pid;
	char	**envp;
	char	*full_path;
	char	**split_path;
	char	*valid_path;
	char	*curpath;
}			t_pipex;
char		*get_path(char *command, t_pipex *pipex);
void		pipex_init(char **argv, char *envp[], t_pipex *pipex);
void		first_child_process(t_pipex *pipex);
void		second_child_process(t_pipex *pipex);
void		free_it(char **str);
void		ft_error_free(t_pipex *pipex);
int			check(char *command);
char		*env_path(char **envp);
void		p_init(t_pipex *pipex);
#endif