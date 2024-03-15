/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:11:49 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/24 15:11:52 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	s[] = "Buenos dias";
	size_t	len = 3;
	int	i;

	i = 0;
	//Desde el comienzo de s los primeros len caracteres serán sustituidos por 0.
	printf("*******************************");
	printf("\nCon len = 3 tiene que aparecer \"000nos dias\"\n");
	ft_bzero((void *)s, len);
	printf("Aparece: ");
	while (i < 11)
	{
		if (ft_isprint(s[i]))
			printf("%c", s[i]);
		else
			printf("%c", s[i] + '0');
		i++;
	}
	printf("\n*******************************");
	return (0);
}
*/
