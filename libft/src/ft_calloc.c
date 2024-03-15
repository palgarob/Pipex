/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:33:55 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/02 18:34:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
/*
int	main(void)
{
	void	*p;

	p = calloc(3, 1);
	printf("%c\n", *(char *)p + '0');
	free(p);
	p = ft_calloc(3, 1);
	printf("%c", *(char *)p + '0');
	free(p);
	return (0);
}
*/
