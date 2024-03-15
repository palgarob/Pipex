/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:27:33 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/23 17:27:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		s++;
		n++;
	}
	return (n);
}

/* int	main(void)
{
	char *s;

	s = (char *)malloc(sizeof(char) * 2);
	s[0] = 'a';
	s[1] = 0;
	printf("Dirección de s:			%p\n", &s);
	printf("Dirección guardada en s:	%p\n", s);
	printf("Cadena guardada en s:		%s\n", s);
	printf("Longitud de s:			%zu\n\n\n", ft_strlen(s));
	free(s);
	printf("Dirección de s:			%p\n", &s);
	printf("Dirección guardada en s:	%p\n", s);
	printf("Cadena guardada en s:		%s\n", s);
	printf("Longitud de s:			%zu", ft_strlen(s));
	return (0);
} */
