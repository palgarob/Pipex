/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:11:41 by pepaloma          #+#    #+#             */
/*   Updated: 2023/10/24 16:11:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	n;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = ft_strlen(str);
	write(1, str, n);
	return (n);
}
