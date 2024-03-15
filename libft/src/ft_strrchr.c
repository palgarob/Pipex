/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:42:09 by pepaloma          #+#    #+#             */
/*   Updated: 2023/01/25 18:42:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strrchr(const char *s, int c)
{
	c = (char)c;
	if (!c)
		return (ft_strchr(s, c));
	if (!ft_strchr(s + 1, c))
		return (ft_strchr(s, c));
	return (ft_strrchr(s + 1, c));
} */

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	c = (char)c;
	len = ft_strlen(s);
	if (!len && c)
		return (NULL);
	if (!c)
		return ((char *)&s[len]);
	while (--len)
		if (s[len] == c)
			return ((char *)&s[len]);
	if (s[len] == c)
		return ((char *)&s[len]);
	return (NULL);
}
/* int	main(void)
{
	char	*s = NULL;
	int	c = '\0';

	printf("%p\n", strrchr(s, c));
	printf("%p", ft_strrchr(s, c));
	return (0);
 }
 */
