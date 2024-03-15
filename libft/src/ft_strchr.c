/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:02:41 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/25 18:02:49 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	if (*s == c)
		return ((char *)s);
	while (*s++)
	{
		if (*s == c)
			return ((char *)s);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*s = "teste";
	int	c = 'e';
	char	*t;

	t = ft_strchr(s, c);
	printf("%p\n", &s[1]);
	printf("%p", t);
	return (0);
}
*/
