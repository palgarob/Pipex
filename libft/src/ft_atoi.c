/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:57:34 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/30 18:57:36 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number(char *s)
{
	int	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

static int	count_spaces(char *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == '\n')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	str += count_spaces((char *)str);
	if (*str == '-')
		return (number((char *)str + 1) * -1);
	if (*str == '+')
		return (number((char *)str + 1));
	return (number((char *)str));
}
/*
int	main(void)
{
	const char	*str = "   u";

	printf("%d\n", atoi(str));
	printf("%d", ft_atoi(str));
	return (0);
}
*/
