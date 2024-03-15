/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:58:12 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/09 13:58:27 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Esta función solo funciona si tienes un puntero donde guardar position */
int	ft_array2d_search(t_array2d array2d, char c, t_point *position)
{
	position->x = 0;
	position->y = 0;
	while (position->y < array2d.size.y)
	{
		position->x = 0;
		while (position->x < array2d.size.x)
		{
			if (array2d.array[position->y][position->x] == c)
				return (1);
			position->x++;
		}
		position->y++;
	}
	return (0);
}
