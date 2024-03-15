/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:25:39 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/24 18:25:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = dstsize;
	i = ft_strlen(src);
	if (n)
		n--;
	while (n-- && *src)
	{
		*(dst++) = *(src++);
	}
	if (dstsize)
		*dst = 0;
	return (i);
}
/*Es importante mencionar que si en strlcpy dst es NULL, ocurre un segmentation
fall. En mi ft_strlcpy también, o sea que damos por hecho que perfecto todo.*/
/*
int	main(void)
{
	char	src[] = "abc";
	char	dst[20] = "x";
	char	src1[] = "abc";
	char	dst1[20] = "x";
	size_t	n = 0;

	printf("%zu\n%s\n\n", strlcpy(dst, src, n), dst);
	printf("%zu\n%s\n", ft_strlcpy(dst1, src1, n), dst1);
	return (0);
}
*/
