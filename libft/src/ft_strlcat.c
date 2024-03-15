/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:24:08 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/25 16:24:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
			size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize < ft_strlen(dst))
	{
		j = 0;
		i = ft_strlen(src) + dstsize;
	}
	else
	{
		j = dstsize - ft_strlen(dst);
		i = ft_strlen(src) + ft_strlen(dst);
	}
	while (*dst)
		dst++;
	ft_strlcpy(dst, src, j);
	return (i);
}
/*
int	main(void)
{
	char	src[20] = "abcder";
	char	dst[20] = "xyzwi";
	char	src1[20] = "abcder";
	char	dst1[20] = "xyzwi";
	size_t	n = 7;


	printf("%zu\n%s\n\n", strlcat(dst, src, n), dst);
	printf("%zu\n%s\n", ft_strlcat(dst1, src1, n), dst1);
	return (0);
}
*/
