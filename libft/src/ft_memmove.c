/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:28:14 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/24 17:28:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dest > sorc)
	{
		while (len-- > 0)
		{
			dest[len] = sorc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
int	main(void)
{
	char	str[] = "kaixo zelan?";
	char	*dst;
	char	*src;
	int	i = 0;

	dst = &(str[0]);
	src = &(str[3]);
	printf("*******************************\n");
	printf("Este es el string antes   de memcpy: %s\n", str);
	printf("Este es el string después de memcpy: ");
	ft_memmove(dst, src, 4);
	while (i < 12)
	{
		if (ft_isprint(str[i]))
			printf("%c", str[i]);
		else
			printf("%c", str[i] + '0');
		i++;
	}
	printf("\n*******************************");
	return (0);
}
*/
