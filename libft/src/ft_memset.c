/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:25 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/23 18:47:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len > 0)
	{
		*a = (unsigned char)c;
		a++;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char	s[] = "Buenos dias";
	char	c = '~';
	size_t	len = 3;

	//Desde el comienzo de s los primeros len caracteres
	//serán sustituidos por el caracter c.
	printf("*******************************");
	printf("\nCon len = 3 tiene que aparecer \"~~~nos dias\"\n");
	printf("Aparece: %s\n", (char *)ft_memset((void *)s, c, len));
	printf("*******************************");
	return (0);
}
*/
