/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:52:12 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Do I have to consider a case where it can't find the PATH variable? */
static char	**get_pathvar_directories(char	**envp)
{
	char	**pathvar_directories;

	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 5))
			break ;
		envp++;
	}
	pathvar_directories = ft_split(&(*envp)[5], ':');
	if (!pathvar_directories)
		return (ft_error_ptr("", 0, 0, 0));
	return (pathvar_directories);
}

static void	first_fork(t_pipex *pipex, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("", clear_struct, pipex, 1);
	if (!pid)
	{
		if (dup2(pipex->pipe_end[1], STDOUT_FILENO) < 0
			|| dup2(pipex->fd1, STDIN_FILENO) < 0)
			ft_error("", clear_struct, pipex, 1);
		close(pipex->pipe_end[0]);
		close(pipex->pipe_end[1]);
		execve(pipex->cmd_path1, pipex->cmd_args1, envp);
	}
	waitpid(pid, NULL, WNOHANG);
}

static void	second_fork(t_pipex *pipex, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("", clear_struct, pipex, 1);
	if (!pid)
	{
		if (dup2(pipex->pipe_end[0], STDIN_FILENO) < 0
			|| dup2(pipex->fd2, STDOUT_FILENO) < 0)
			ft_error("", clear_struct, pipex, 1);
		close(pipex->pipe_end[0]);
		close(pipex->pipe_end[1]);
		execve(pipex->cmd_path2, pipex->cmd_args2, envp);
	}
	waitpid(pid, NULL, WNOHANG);
}

static void	init_pipex(t_pipex *pipex, char **envp)
{
	pipex->close_pipes = 0;
	pipex->close_fd1 = 0;
	pipex->close_fd2 = 0;
	pipex->cmd_path1 = 0;
	pipex->cmd_path2 = 0;
	pipex->cmd_args1 = 0;
	pipex->cmd_args2 = 0;
	pipex->path_var_directories = get_pathvar_directories(envp);
	if (!pipex->path_var_directories)
		ft_error(ERROR_PATH_DIR, 0, 0, 1);
}

void	pipex_(t_pipex *pipex, char **envp)
{
	init_pipex(pipex, envp);
	if (pipe(pipex->pipe_end) < 0)
		ft_error("", clear_struct, pipex, 1);
	pipex->close_pipes = 1;
	if (parse_in(pipex, pipex->file1, pipex->cmd1))
		first_fork(pipex, envp);
	if (parse_out(pipex, pipex->file2, pipex->cmd2))
		second_fork(pipex, envp);
	clear_struct(pipex);
}
