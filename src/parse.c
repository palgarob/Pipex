/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:18:20 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 17:17:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_cmd_args(char *cmd1)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd1, ' ');
	if (!cmd_args)
		return (ft_error_ptr("", 0, 0, 0));
	return (cmd_args);
}

static char	*get_cmd_path(char **path_var_dir, char *cmd_name)
{
	char	*cmd_path;

	while (*path_var_dir)
	{
		cmd_path = (char *)malloc(
				sizeof(char) * (
					ft_strlen(*path_var_dir) + ft_strlen(cmd_name) + 2
					)
				);
		if (!cmd_path)
			return (ft_error_ptr("", 0, 0, 0));
		*cmd_path = 0;
		ft_strlcat(
			cmd_path, *path_var_dir, ft_strlen(*path_var_dir) + 1
			);
		ft_strlcat(cmd_path, "/", ft_strlen(cmd_path) + 2);
		ft_strlcat(
			cmd_path, cmd_name, ft_strlen(cmd_path) + ft_strlen(cmd_name) + 1
			);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		path_var_dir++;
	}
	return (NULL);
}

static int	cmd_error(char *cmd)
{
	char	*message;

	errno = 0;
	message = ft_strjoin(cmd, ERROR_CMD_NOT_FOUND);
	if (!message)
		return (ft_error("", 0, 0, 0));
	errno = 0;
	return (ft_error(message, free, message, 0));
}

int	parse_in(t_pipex *pipex, const char *file1, const char *cmd1)
{
	pipex->fd1 = open(file1, O_RDONLY);
	if (pipex->fd1 < 0)
		return (ft_error(file1, 0, 0, 0));
	pipex->close_fd1 = 1;
	pipex->cmd_args1 = get_cmd_args((char *)cmd1);
	if (!pipex->cmd_args1)
		return (0);
	pipex->cmd_path1 = get_cmd_path(
			pipex->path_var_directories, pipex->cmd_args1[0]
			);
	if (!pipex->cmd_path1)
		return (cmd_error(pipex->cmd_args1[0]));
	return (1);
}

int	parse_out(t_pipex *pipex, const char *file2, const char *cmd2)
{
	pipex->fd2 = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd2 < 0)
	{
		ft_error(file2, 0, 0, 0);
		return (0);
	}
	pipex->close_fd2 = 1;
	pipex->cmd_args2 = get_cmd_args((char *)cmd2);
	if (!pipex->cmd_args2)
		return (0);
	pipex->cmd_path2 = get_cmd_path(
			pipex->path_var_directories, pipex->cmd_args2[0]
			);
	if (!pipex->cmd_path2)
		return (cmd_error(pipex->cmd_args2[0]));
	return (1);
}
