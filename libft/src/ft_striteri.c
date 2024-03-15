/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:38:29 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(unsigned int i, char *s)
{
	*s += i;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
int	main(void)
{
	char	s[] = "abcdef";

	ft_striteri(s, f);
	printf("%s", s);
	//printf("%c", f(1, 'a'));
	return (0);
}
*/
