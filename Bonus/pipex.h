/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:39 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/23 08:28:51 by kait-baa         ###   ########.fr       */
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
# include "../get_next_line/get_next_line.h"
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
	char	*path;
	char	**cmd;
	int		infile;
	int		outfile;
	pid_t	pid;
	int		argc;
	char	**argv;
	char	**envp;
	char	*line;
	int		ffd;
	char	*full_path;
	char	**split_path;
	char	*valid_path;
	char	*curpath;
}			t_pipex;
typedef struct s_path
{
	int		i;
	char	*bigpath;
	char	*commandpath;
	char	**split_path;
}			t_path;
char		*get_path(char *command, t_pipex *pipex);
void		pipex_init(char **argv, char *envp[], t_pipex *pipex);
void		free_it(char **str);
void		ft_error_free(t_pipex *pipex, int i);
void		execute_command(t_pipex *pipex, int *fd);
void		open_file(t_pipex *pipex, char **argv, int argc);
void		first_child_process(t_pipex *pipex, int *fd);
void		last_child_process(t_pipex *pipex);
void		ft_here_doc(char *limiter, t_pipex *pipex);
void		exit_err(int i, char *err);
void		p_pipe(t_pipex *pipex);
int			check(char *command);
char		*env_path(char **envp);
void		exec_init(t_pipex *pipex, int i);
void		p_init(t_pipex *pipex, char **argv, char **envp, int argc);
#endif