/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:48:02 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/30 16:48:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int	main(void)
{
	char	s1[10] = "abcdefghij";
	char	s2[10] = "abcdefgxyz";
	char	*s1n = NULL;
	char	*s2n = NULL;
	size_t	n = 7;
	size_t	n0 = 0;

	printf("s1: NULL s2: NULL n: 0\n");
	printf("%d\n", memcmp(s1n, s2n, n0));
	printf("%d\n\n", ft_memcmp(s1n, s2n, n0));

	printf("s1: NULL s2: NULL n: !0\n");
//	printf("%d\n", memcmp(s1n, s2n, n));
//	printf("%d\n\n", ft_memcmp(s1n, s2n, n));

	printf("s1: NULL s2: !NULL n: 0\n");
	printf("%d\n", memcmp(s1n, s2, n0));
	printf("%d\n\n", ft_memcmp(s1n, s2, n0));

	printf("s1: NULL s2: !NULL n: !0\n");
//	printf("%d\n", memcmp(s1n, s2, n));
//	printf("%d\n\n", ft_memcmp(s1n, s2, n));

	printf("s1: !NULL s2: NULL n: 0\n");
	printf("%d\n", memcmp(s1, s2n, n0));
	printf("%d\n\n", ft_memcmp(s1, s2n, n0));

	printf("s1: !NULL s2: NULL n: !0\n");
//	printf("%d\n", memcmp(s1, s2n, n));
//	printf("%d\n\n", ft_memcmp(s1, s2n, n));

	printf("s1: !NULL s2: !NULL n: 0\n");
	printf("%d\n", memcmp(s1, s2, n0));
	printf("%d\n\n", ft_memcmp(s1, s2, n0));

	printf("s1: !NULL s2: !NULL n: !0\n");
	printf("%d\n", memcmp(s1, s2, n));
	printf("%d\n", ft_memcmp(s1, s2, n));

	return (0);
}
*/
