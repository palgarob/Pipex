/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:28:45 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/11 12:05:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(char **array, t_point *size)
{
	size->x = ft_strlen(*array);
	size->y = 0;
	while (*array)
	{
		if (size->x != (int)ft_strlen(*array))
			return (ft_error(ERROR_ARRAY2DSIZE, 0, 0, 0));
		array++;
		size->y++;
	}
	return (1);
}

char	**ft_array2d_create(int fd, char c)
{
	char	*str;
	char	*line;
	char	**array;

	if (fd < 0)
		return (NULL);
	str = 0;
	line = ft_gnl(fd);
	while (line)
	{
		str = ft_strjoin_gnl(str, line);
		free(line);
		line = ft_gnl(fd);
		if (!line && errno)
		{
			str = 0;
			return (NULL);
		}
	}
	array = ft_split(str, c);
	free(str);
	if (!array)
		return (NULL);
	return (array);
}
