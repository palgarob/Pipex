/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:38:23 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/02 19:38:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = (char *)malloc(ft_strlen(s1) + 1);
	if (s)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
/*
int	main(void)
{
	char	*t1 = "";
	char	*t2;
	char	*t3;

	t2 = strdup(t1);
	t3 = ft_strdup(t1);
	printf("%s\n%s", t2, t3);
	if (*t2 == *t3)
		printf("SUCCES");
	return (0);
}
*/
