/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:47:12 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/30 15:47:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		n--;
		s++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[10] = "hola";
	size_t	n = 9;

	ft_memset((void *)&s[6], 'p', 1);
	printf("%c\n", s[6]);
	printf("%p\n", memchr(s, 'p', n));
	printf("%p\n", ft_memchr(s, 'p', n));
	return (0);
}
*/
