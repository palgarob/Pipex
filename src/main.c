/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:35:31 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error(ERROR_ARGNUM, 0, 0, 1);
	pipex.file1 = argv[1];
	pipex.file2 = argv[4];
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	pipex_(&pipex, envp);
	return (0);
}
