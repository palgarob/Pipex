/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:38:23 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/14 18:38:27 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	f(unsigned int i, char c)
{
	char	d;


	d = c + i;
	return (d);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*str;

	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char	*s = "abcdefg";

	printf("%s", ft_strmapi(s, f));
	//printf("%c", f(1, 'a'));
	return (0);
}
*/
