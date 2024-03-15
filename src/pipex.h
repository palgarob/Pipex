/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:36:02 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:36 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// LIBRARIES INCLUDED
# include "../libft/src/libft.h"
# include <sys/wait.h>

// ERRORS
# define ERROR_ARGNUM "The number of arguments must be 4\n"
# define ERROR_CMD_NOT_FOUND ": Command not found\n"
# define ERROR_PATH_DIR "The variable with the PATH directories couldn't be \
created"

typedef struct s_pipex
{
	const char	*file1;
	const char	*file2;
	const char	*cmd1;
	const char	*cmd2;
	int			close_pipes;
	int			close_fd1;
	int			close_fd2;
	int			pipe_end[2];
	int			fd1;
	int			fd2;
	char		**cmd_args1;
	char		**cmd_args2;
	char		*cmd_path1;
	char		*cmd_path2;
	char		**path_var_directories;
}	t_pipex;

void	pipex_(t_pipex *pipex, char **envp);
int		parse_in(t_pipex *pipex, const char *file1, const char *cmd1);
int		parse_out(t_pipex *pipex, const char *file2, const char *cmd2);
void	clear_struct(void *param);
void	close_fd(void *param);

#endif
