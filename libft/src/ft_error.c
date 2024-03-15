/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:13:38 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/21 10:35:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This file contains functions for error handling*/

#include "libft.h"

void	*ft_error_ptr(const char *err_message,
void (*free_func)(void *), void *content, int exit_bool)
{
	if (err_message)
	{
		if (errno || !ft_strlen(err_message))
			perror(err_message);
		else
			write(STDERR_FILENO, err_message, ft_strlen(err_message));
	}
	if (free_func)
		free_func(content);
	if (exit_bool)
		exit(1);
	else
		return (NULL);
}

int	ft_error(const char *err_message,
void (*free_func)(void *), void *content, int exit_bool)
{
	if (err_message)
	{
		if (errno || !ft_strlen(err_message))
			perror(err_message);
		else
			write(STDERR_FILENO, err_message, ft_strlen(err_message));
	}
	if (free_func)
		free_func(content);
	if (exit_bool)
		exit(1);
	else
		return (0);
}
