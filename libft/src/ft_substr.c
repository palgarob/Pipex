/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:16:42 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/06 12:16:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	array_len;

	if (!*s)
		start = 0;
	if (ft_strlen(s + start) < len)
		array_len = ft_strlen(s + start) + 1;
	else
		array_len = len + 1;
	ss = (char *)malloc(array_len);
	if (!ss)
		return (NULL);
	if (!*s || start > ft_strlen(s + start))
		array_len = 1;
	ft_strlcpy(ss, s + start, array_len);
	return (ss);
} */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (*s)
	{
		if (start > ft_strlen(s))
			start = ft_strlen(s);
		s = s + start;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, s, len + 1);
	return (ss);
}
/*
int	main(void)
{
//	char	s[] = "lorem ipsum dolor sit amet";
//	char	*s0 = "";

//	unsigned int	start = 2;
//	unsigned int	start0 = 0;

//	size_t	len = 3;
//	size_t	len0 = 0;

//	printf("s start len\n");
//	printf("%s\n\n", ft_substr(s, 400, 20));
//	printf("s start 0\n");
//	printf("%s\n\n", ft_substr(s, start, len0));
//	printf("s 0 len\n");
//	printf("%s\n\n", ft_substr(s, start0, len));
//	printf("s 0 0\n");
//	printf("%s\n\n", ft_substr(s, start0, len0));
//	printf("0 start len\n");
//	printf("%s\n\n", ft_substr(s0, start, len));
//	printf("0 start 0\n");
//	printf("%s\n\n", ft_substr(s0, start, len0));
//	printf("0 0 len\n");
//	printf("%s\n\n", ft_substr(s0, start0, len));
//	printf("0 0 0\n");
//	printf("%s\n\n", ft_substr(s0, start0, len0));

	printf("%s", ft_substr("", 1, 1));
	return (0);
} */
