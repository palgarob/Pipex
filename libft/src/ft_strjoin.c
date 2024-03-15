/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:20:45 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/06 12:20:48 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s;
	size_t	joint_len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	joint_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(sizeof(char) * joint_len);
	if (!s)
	{
		free(s1);
		return (NULL);
	}
	*s = 0;
	ft_strlcat(s, (char *)s1, joint_len);
	free(s1);
	ft_strlcat(s, (char *)s2, joint_len);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	joint_len;

	joint_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(sizeof(char) * joint_len);
	if (!s)
		return (NULL);
	*s = 0;
	ft_strlcat(s, (char *)s1, joint_len);
	ft_strlcat(s, (char *)s2, joint_len);
	return (s);
}
/*
int	main(void)
{
	char	s1[4] = "abc";
	char	s2[20] = "xyz";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}
*/
