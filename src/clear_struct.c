/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:29:26 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 17:11:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(void *param)
{
	int	*fd;

	fd = (int *)param;
	close(*fd);
}

void	clear_struct(void *param)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)param;
	ft_array2d_free(
		pipex->path_var_directories, ft_array2d_len(pipex->path_var_directories)
		);
	if (pipex->close_pipes)
	{
		close(pipex->pipe_end[0]);
		close(pipex->pipe_end[1]);
	}
	if (pipex->close_fd1)
		close(pipex->fd1);
	if (pipex->close_fd2)
		close(pipex->fd2);
	if (pipex->cmd_args1)
		ft_array2d_free(pipex->cmd_args1, ft_array2d_len(pipex->cmd_args1));
	if (pipex->cmd_args2)
		ft_array2d_free(pipex->cmd_args2, ft_array2d_len(pipex->cmd_args2));
	if (pipex->cmd_path1)
		free(pipex->cmd_path1);
	if (pipex->cmd_path2)
		free(pipex->cmd_path2);
}
