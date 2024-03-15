/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_valid_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:54:36 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/22 12:24:28 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_fillable(char **tab, t_point size,
t_point position, const char *fillable)
{
	int	checker;
	int	i;

	i = 0;
	checker = 0;
	while (fillable[i])
	{
		if (tab[position.y][position.x] == fillable[i++])
		{
			checker = 1;
			break ;
		}
	}
	if (
		position.x < size.x
		&& position.x >= 0
		&& position.y < size.y
		&& position.y >= 0
		&& checker
	)
		return (1);
	return (0);
}

static void	ft_flood_fill(char **tab, t_point size,
t_point position, const char *fillable)
{
	t_point	next;

	if (check_fillable(tab, size, position, fillable))
	{
		tab[position.y][position.x] = 'F';
		next.y = position.y;
		next.x = position.x + 1;
		ft_flood_fill(tab, size, next, fillable);
		next.y = position.y + 1;
		next.x = position.x;
		ft_flood_fill(tab, size, next, fillable);
		next.y = position.y;
		next.x = position.x - 1;
		ft_flood_fill(tab, size, next, fillable);
		next.y = position.y - 1;
		next.x = position.x;
		ft_flood_fill(tab, size, next, fillable);
	}
}

int	ft_array2d_valid_path(t_array2d array2d,
t_point begin, const char *floodplain)
{
	t_array2d	*cpy;
	int			check;

	cpy = ft_array2d_cpy(array2d);
	if (!cpy)
		return (0);
	ft_flood_fill(cpy->array, cpy->size, begin, floodplain);
	check = 0;
	while (*floodplain)
	{
		if (ft_array2d_search(*cpy, *floodplain, &begin))
			check = 1;
		floodplain++;
	}
	if (check)
	{
		ft_array2d_free(cpy->array, cpy->size.y);
		return (ft_error("There is not a valid path", free, cpy, 0));
	}
	return (1);
}
