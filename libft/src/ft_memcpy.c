/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:54 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/24 15:34:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;

	if (!dst && !src)
		return (NULL);
	aux = dst;
	while (n > 0)
	{
		ft_memset(aux, *(unsigned char *)src, 1);
		aux++;
		src++;
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char	*dst = NULL;
	char	*src = NULL;
	int	i = 0;

	printf("*******************************\n");
	memcpy()
	printf("Este es el string dst antes de memcpy: %s\n", dst);
	printf("Este es el string dst después de memcpy: ");
	ft_memcpy(dst, src, 4);
	while (i < 4)
	{
		if (ft_isprint(dst[i]))
			printf("%c", dst[i]);
		else
			printf("%c", dst[i] + '0');
		i++;
	}
	printf("\n*******************************");
	return (0);
}

*/
